# Remocao da barreira de TLUT com recursos imutaveis

Release `408A7829D11811A4EF9D187C02934483D30E31EED64293F9EB4D2E7A52AC0002`, mapa images_active.map, manifesto images_manifest.json. Build0 sem warnings, CTest13/13;215 objetos/GL e11.712 nomes; PGO USE sem coleta. Input fisico preservado, generated/ intacto.

## Evidencia que motivou o patch

Depois de restaurar o cache intradraw do worker, o trecho idle mais estavel anterior ficou em141draws/frame tanto off quanto on. Async off: GAME13.009ms/GX3.182ms/quadro18.404ms; on: GAME13.983ms/GX3.327ms/quadro19.689ms. Mesmo numero de draws nao prova igualdade de toda fisica/animacao, mas nao houve ganho confirmado. Na primeira sequencia houve troca de carga/pausa/transicao e ela nao foi usada como A/B controlado.

Fila drenava~1.15jobs por barreira. Amostragem nativa exclusivaGX(63pilhas) localizou17esperas SDL de async_raw_drain:11atingiam flush_efb diretamente no parser e6a copia de texturaEFB. As11do parser retornavam no RVA0x8FE43 do binario221D241B. Disassembly verificado: cmp dil,0x65 em0x8FE31 e call flush_efb em0x8FE3E. Portanto era a carga de paletaBP65/TLUT, nao uma espera abstrata de VBlank. Outras5amostras de async_raw_drain estavam publicando cache.

Artefatos: async_barrier_stacks.txt; async_idle_off_repeat.json; async_idle_on_repeat.json. O sampler foi executado DEPOIS dos timers e a coleta ja usava seek/tail, sem reler42MB a cada250ms.

## Codigo aplicado

- gx_images.c/h: versoes imutaveis de bytes fonte e paletas, referencias por draw, identidade exata SourceID/PaletteID, hash com comparacao integral da paleta e comparacao de bytes quando paginas RAM mudam. Fontes usam geracoes4KB em user-space para caminho comum, sem GetWriteWatch adicional por lookup. Escrita vizinha na mesma pagina atualiza metadados mas preserva a identidade quando os pixels nao mudaram.
- Pools limitados a128fontes/32MiB e128paletas/max32KiB cada; referencias impedem evict de dados usados por draws pendentes. Dados alterados ganham outra versao; a anterior permanece ate renderizacao. Falha de memoria/capacidade faz flush imediato conservador.
- gx_pipe.c: snapshots ficam em array paralelo ao QueuedDraw, preservando o formato de captura/replay. Cada draw guarda recursos das unidades TEV usadas. Identidade64bit entra na chave da texturaGPU; uma versao ja convertida emVRAM nao e re-hasheada/re-upada por simples mudanca de epochTLUT.
- BP65 atualizaTMEM sem flush de draws que ja possuem recursos imutaveis. CapturasGXC e modo de referencia continuam com flush antigo. CopiasEFB/DrawDone/tokens mantem as barreiras e IRQs. I4VRAM continua usando handlesGPU, sem copiar pixelsGPU paraRAM.
- Merge de draws exige tambem igualdade das versoes de imagem, alem de material/XF. Recursos sao liberados aposconsumo,clearou shutdown; worker continua sem ponteirosRAM guest ouGL.

Somente congelar a paleta seria insuficiente: o teste novo tambem modifica os indices da texturaRAM antes deGXCopyDisp, portanto os pixels fonte sao congelados igualmente. Isso evita depender de buffers CPU continuarem intocados aposenqueue.

## Validacao

Teste independente: copy-on-write da fonte, paleta por valor, identidade preservada em escrita fora da imagem na mesma4KBpagina,128lookups sem syscalls. Teste integrado enfileira drawvermelho, troca pixels/paleta para drawverde e reutiliza ambos os buffers antes da copia; vermelho e verde preservados software/OpenGL. Teste de cache de paletas agora exige ausencia de novos uploads apos aquecimento e limite de no maximo2uploads iniciais, permitindo reutilizacao entre conteudos iguais.

Contratos de endian,callbacks/FPU/CPU/RAM,vertices425.984,AX/DVD,PE/IRQ,DLs,YUY2 eVRAM anteriores continuam passando. Replay antigo de17batches leu o formato sem migracao e gerouBMP byte a byte identico: `2FCE270E6B0B00A3C9969019D175432DCDD222F85AA6F4D2C399C2677D828B79` antes/depois.

## Controles e limites

Cfg campo20 async_decode=1,21 immutable_images=1 por padrao, inclusive quando os campos estao ausentes. Campo21=0 drena e restaura a barreiraTLUT para comparacao na mesma luta; campo20 controla apenas o worker. Frame60 inclui flags reais e contadores image_copy_bytes,palette_copy_bytes,tlut_deferred,tlut_sync,image_fallbacks,alem de reuse/drains/wait/snapshot do worker.

Raw arrays/GL/EFB ainda tem dependencias reais: nao se removeu toda sincronizacao nem se adiantou conclusaoPE artificialmente. Parser/estado/GL permanecem main; worker prepara missesraw. Nao se declara60FPS nem ganho previsto de4.5ms. Medicao desta revisao aguarda confirmacao fisica com quatro humanos parados; primeiro e preciso verificar se TLUTfoi adiado e se jobs/drain aumentaram.
