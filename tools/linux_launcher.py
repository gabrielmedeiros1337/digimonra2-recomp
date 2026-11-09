#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Digimon Rumble Arena 2 - PC Port
Lightweight Native Linux Launcher (Python 3 / Tkinter)
Bilingual (PT-BR / EN) - Reads and writes config/launcher_config.json
"""

import os
import sys
import json
import subprocess
import tkinter as tk
from tkinter import ttk, filedialog, messagebox

CONFIG_PATH = os.path.join("config", "launcher_config.json")
DEFAULT_KEYS = [29, 27, 6, 25, 43, 40, 20, 8, 26, 22, 4, 7, 82, 81, 80, 79, 12, 14, 13, 15]

STRINGS = {
    "pt-BR": {
        "title": "DIGIMON RUMBLE ARENA 2",
        "subtitle": "PC Port - Static Recompilation",
        "tab_play": "Jogar",
        "tab_controls": "Controles",
        "tab_options": "Opções",
        "tab_credits": "Créditos",
        "disc_box": "IMAGEM DO DISCO (GAMECUBE USA)",
        "disc_label": "Arquivo do Jogo (ISO / CISO / NKit / RVZ):",
        "browse": "Procurar...",
        "disc_hint": "Formatos suportados: .iso, .ciso, .nkit.iso, .rvz (dump original americano NTSC-U).",
        "card_box": "MEMORY CARD (SLOT A)",
        "card_label": "Status do Cartão de Memória:",
        "card_detected": "Memory Card detectado em saves/MemoryCardA.card",
        "card_new": "[NOVO] saves/MemoryCardA.card será inicializado ao iniciar o jogo",
        "card_locked": "[BLOQUEADO] Outro processo está acessando o Memory Card",
        "open_saves": "Abrir pasta de saves",
        "card_desc": "Armazenamento portátil localizado em saves/MemoryCardA.card (compatível e transferível)",
        "btn_play": "JOGAR",
        "btn_save": "Salvar Ajustes",
        "status_engine": "Aceleração gráfica OpenGL por hardware · Taxa de quadros cravada em 60 FPS",
        "lang_btn": "🌐 Idioma: PT-BR",
        "saved_msg": "Configurações salvas com sucesso!",
        "error_no_disc": "Por favor selecione a imagem do disco do jogo (.iso, .ciso, .rvz) antes de iniciar.",
        "opt_display_box": "CONFIGURAÇÃO DE VÍDEO",
        "opt_internal_res": "Resolução Interna 3D:",
        "opt_aspect": "Proporção de Tela (Aspect Ratio):",
        "opt_aspect_4_3": "4:3 (Original GameCube)",
        "opt_aspect_16_9": "16:9 (Widescreen Hor+ Nativo)",
        "opt_window_mode": "Modo de Janela:",
        "opt_window_windowed": "Janela",
        "opt_window_borderless": "Sem bordas (Borderless)",
        "opt_window_exclusive": "Tela Cheia Exclusiva",
        "opt_window_res": "Resolução da Janela:",
        "opt_vsync": "Sincronização Vertical (VSync)",
        "opt_unlock": "Desbloquear Tudo (Personagens e Fases)",
        "ctrl_box": "CONFIGURAÇÃO DE CONTROLES",
        "ctrl_p1": "Jogador 1 (Porta 1):",
        "ctrl_p2": "Jogador 2 (Porta 2):",
        "ctrl_p3": "Jogador 3 (Porta 3):",
        "ctrl_p4": "Jogador 4 (Porta 4):",
        "ctrl_device_keyboard": "Teclado",
        "ctrl_device_auto": "Gamepad / Controle USB (Auto)",
        "ctrl_device_none": "Desconectado",
        "credits_box": "CRÉDITOS DO PROJETO",
        "credits_text": (
            "DIGIMON RUMBLE ARENA 2 - PC PORT\n\n"
            "Desenvolvido por: Gabriel Medeiros (gabrielmedeiros1337)\n\n"
            "Port nativo baseado em engenharia reversa e recompilação estática\n"
            "do executável original de Nintendo GameCube (USA NTSC-U).\n\n"
            "Renderizador: OpenGL 3.3 Core Profile com pipeline HLE GX.\n"
            "Taxa de quadros: 60 FPS nativo com proporção Widescreen 16:9 real.\n"
            "Entrada e Áudio: SDL2 nativo.\n\n"
            "Este projeto não contém nenhuma propriedade intelectual protegida,\n"
            "código binário do jogo ou dados de áudio/vídeo proprietários da Bandai."
        )
    },
    "en": {
        "title": "DIGIMON RUMBLE ARENA 2",
        "subtitle": "PC Port - Static Recompilation",
        "tab_play": "Play",
        "tab_controls": "Controls",
        "tab_options": "Options",
        "tab_credits": "Credits",
        "disc_box": "GAME DISC IMAGE (GAMECUBE USA)",
        "disc_label": "Game Disc Image (ISO / CISO / NKit / RVZ):",
        "browse": "Browse...",
        "disc_hint": "Supported formats: .iso, .ciso, .nkit.iso, .rvz (original USA NTSC-U dump).",
        "card_box": "MEMORY CARD (SLOT A)",
        "card_label": "Memory Card Status:",
        "card_detected": "Memory Card detected in saves/MemoryCardA.card",
        "card_new": "[NEW] saves/MemoryCardA.card will be created on first launch",
        "card_locked": "[LOCKED] Another process is using the Memory Card",
        "open_saves": "Open saves folder",
        "card_desc": "Portable storage located at saves/MemoryCardA.card (compatible and transferable)",
        "btn_play": "PLAY",
        "btn_save": "Save Settings",
        "status_engine": "Hardware-accelerated OpenGL graphics · Locked 60 FPS",
        "lang_btn": "🌐 Language: EN",
        "saved_msg": "Settings saved successfully!",
        "error_no_disc": "Please select the game disc image (.iso, .ciso, .rvz) before launching.",
        "opt_display_box": "VIDEO CONFIGURATION",
        "opt_internal_res": "Internal 3D Resolution:",
        "opt_aspect": "Aspect Ratio:",
        "opt_aspect_4_3": "4:3 (Original GameCube)",
        "opt_aspect_16_9": "16:9 (Native Hor+ Widescreen)",
        "opt_window_mode": "Window Mode:",
        "opt_window_windowed": "Windowed",
        "opt_window_borderless": "Borderless Fullscreen",
        "opt_window_exclusive": "Exclusive Fullscreen",
        "opt_window_res": "Window Resolution:",
        "opt_vsync": "Vertical Sync (VSync)",
        "opt_unlock": "Unlock All (Characters & Stages)",
        "ctrl_box": "CONTROLLER CONFIGURATION",
        "ctrl_p1": "Player 1 (Port 1):",
        "ctrl_p2": "Player 2 (Port 2):",
        "ctrl_p3": "Player 3 (Port 3):",
        "ctrl_p4": "Player 4 (Port 4):",
        "ctrl_device_keyboard": "Keyboard",
        "ctrl_device_auto": "Gamepad / USB Controller (Auto)",
        "ctrl_device_none": "Disconnected",
        "credits_box": "PROJECT CREDITS",
        "credits_text": (
            "DIGIMON RUMBLE ARENA 2 - PC PORT\n\n"
            "Developed by: Gabriel Medeiros (gabrielmedeiros1337)\n\n"
            "Native PC port based on static recompilation of the original\n"
            "Nintendo GameCube executable (USA NTSC-U).\n\n"
            "Renderer: OpenGL 3.3 Core Profile with HLE GX pipeline.\n"
            "Framerate: Locked native 60 FPS with true 16:9 widescreen.\n"
            "Input and Audio: Native SDL2.\n\n"
            "This project contains no copyrighted assets, game ROMs, or\n"
            "proprietary audio/video data owned by Bandai."
        )
    }
}

INTERNAL_RES_OPTIONS = [
    "1x (640x528) - Native GameCube",
    "1.5x (960x792) - Smooth 720p",
    "2x (1280x1056) - HD 1080p",
    "3x (1920x1584) - 2K Quad HD",
    "4x (2560x2112) - Ultra HD 4K"
]

WINDOW_RES_OPTIONS = [
    "640x480",
    "1280x720 (720p)",
    "1366x768",
    "1600x900",
    "1920x1080 (1080p)",
    "2560x1440 (1440p)",
    "3840x2160 (4K UHD)"
]

def load_config():
    default_cfg = {
        "version": 1,
        "vsync": False,
        "window_mode": 0,
        "window_resolution": 1,
        "internal_resolution": 0,
        "aspect_ratio": 0,
        "unlock_all": False,
        "language": "pt-BR",
        "image_path": "",
        "keyboard_enabled": True,
        "keyboard_port": 0,
        "ports": ["keyboard", "none", "none", "none"],
        "keys": DEFAULT_KEYS
    }
    if os.path.exists(CONFIG_PATH):
        try:
            with open(CONFIG_PATH, "r", encoding="utf-8") as f:
                data = json.load(f)
                default_cfg.update(data)
        except Exception:
            pass
    return default_cfg

def save_config(cfg):
    os.makedirs(os.path.dirname(CONFIG_PATH), exist_ok=True)
    with open(CONFIG_PATH, "w", encoding="utf-8") as f:
        json.dump(cfg, f, indent=2)

class LinuxLauncher(tk.Tk):
    def __init__(self):
        super().__init__()
        self.config_data = load_config()
        self.cur_lang = self.config_data.get("language", "pt-BR")
        if self.cur_lang not in STRINGS:
            self.cur_lang = "pt-BR"
        
        self.title("Digimon Rumble Arena 2 - PC Launcher")
        self.geometry("860x600")
        self.minsize(800, 560)
        self.configure(bg="#050d18")

        self.setup_styles()
        self.create_widgets()
        self.update_language()

    def tr(self, key):
        return STRINGS[self.cur_lang].get(key, key)

    def setup_styles(self):
        style = ttk.Style(self)
        style.theme_use("clam")

        # Custom dark cyber palette
        bg_dark = "#050d18"
        bg_panel = "#0a1728"
        cyan_accent = "#00b4d8"
        orange_accent = "#ff8800"
        fg_text = "#ffffff"

        style.configure("TNotebook", background=bg_dark, borderwidth=0)
        style.configure("TNotebook.Tab", background="#0d223a", foreground="#8ecae6",
                        padding=[18, 8], font=("Segoe UI", 10, "bold"), borderwidth=1)
        style.map("TNotebook.Tab",
                  background=[("selected", orange_accent), ("active", "#12375c")],
                  foreground=[("selected", "#000000"), ("active", "#ffffff")])

        style.configure("TFrame", background=bg_dark)
        style.configure("Panel.TFrame", background=bg_panel, relief="solid", borderwidth=1)
        style.configure("TLabel", background=bg_dark, foreground=fg_text, font=("Segoe UI", 9))
        style.configure("Panel.TLabel", background=bg_panel, foreground=fg_text, font=("Segoe UI", 9))
        style.configure("Header.TLabel", background=bg_dark, foreground="#00e5ff", font=("Segoe UI", 16, "bold"))
        style.configure("SubHeader.TLabel", background=bg_dark, foreground="#8ecae6", font=("Segoe UI", 9))
        style.configure("Section.TLabel", background=bg_panel, foreground="#00e5ff", font=("Segoe UI", 10, "bold"))
        style.configure("Hint.TLabel", background=bg_panel, foreground="#6c8ca8", font=("Segoe UI", 8))

        style.configure("Cyber.TButton", background="#0d2e4f", foreground="#00e5ff",
                        font=("Segoe UI", 9, "bold"), borderwidth=1, focuscolor="none")
        style.map("Cyber.TButton",
                  background=[("active", "#14487a"), ("pressed", "#0a223a")],
                  foreground=[("active", "#ffffff")])

        style.configure("Play.TButton", background=orange_accent, foreground="#000000",
                        font=("Segoe UI", 14, "bold"), borderwidth=0, focuscolor="none")
        style.map("Play.TButton",
                  background=[("active", "#ffa033"), ("pressed", "#cc6d00")],
                  foreground=[("active", "#000000")])

        style.configure("TRadiobutton", background=bg_panel, foreground=fg_text, font=("Segoe UI", 9))
        style.configure("TCheckbutton", background=bg_panel, foreground=fg_text, font=("Segoe UI", 9))
        style.configure("TCombobox", fieldbackground="#050d18", background="#0d2e4f", foreground="#ffffff")

    def create_widgets(self):
        # Header bar
        header_frame = tk.Frame(self, bg="#050d18", height=60)
        header_frame.pack(fill=tk.X, padx=16, pady=(12, 6))

        title_box = tk.Frame(header_frame, bg="#050d18")
        title_box.pack(side=tk.LEFT)

        self.lbl_title = tk.Label(title_box, text=self.tr("title"), font=("Impact", 18),
                                  fg="#ffffff", bg="#050d18")
        self.lbl_title.pack(anchor="w")

        self.lbl_subtitle = tk.Label(title_box, text=self.tr("subtitle"), font=("Segoe UI", 9),
                                     fg="#00e5ff", bg="#050d18")
        self.lbl_subtitle.pack(anchor="w")

        # Top-right Language Toggle Button
        self.btn_lang = tk.Button(header_frame, text=self.tr("lang_btn"), font=("Segoe UI", 9, "bold"),
                                  fg="#00e5ff", bg="#0d223a", activebackground="#14487a",
                                  activeforeground="#ffffff", relief="flat", bd=1,
                                  padx=10, pady=4, cursor="hand2", command=self.toggle_language)
        self.btn_lang.pack(side=tk.RIGHT, pady=6)

        # Tab Notebook
        self.notebook = ttk.Notebook(self)
        self.notebook.pack(fill=tk.BOTH, expand=True, padx=16, pady=6)

        # Tabs
        self.tab_play = ttk.Frame(self.notebook)
        self.tab_options = ttk.Frame(self.notebook)
        self.tab_controls = ttk.Frame(self.notebook)
        self.tab_credits = ttk.Frame(self.notebook)

        self.notebook.add(self.tab_play, text=self.tr("tab_play"))
        self.notebook.add(self.tab_controls, text=self.tr("tab_controls"))
        self.notebook.add(self.tab_options, text=self.tr("tab_options"))
        self.notebook.add(self.tab_credits, text=self.tr("tab_credits"))

        self.build_tab_play()
        self.build_tab_options()
        self.build_tab_controls()
        self.build_tab_credits()

        # Footer bar
        footer_frame = tk.Frame(self, bg="#050d18", height=40)
        footer_frame.pack(fill=tk.X, padx=16, pady=(4, 10))

        self.lbl_status = tk.Label(footer_frame, text=self.tr("status_engine"),
                                   font=("Segoe UI", 8), fg="#527896", bg="#050d18")
        self.lbl_status.pack(side=tk.LEFT, pady=4)

        self.btn_save_settings = tk.Button(footer_frame, text=self.tr("btn_save"),
                                           font=("Segoe UI", 9, "bold"), fg="#ffffff", bg="#0d2e4f",
                                           activebackground="#14487a", activeforeground="#ffffff",
                                           relief="flat", padx=12, pady=4, cursor="hand2",
                                           command=self.on_save_button)
        self.btn_save_settings.pack(side=tk.RIGHT, pady=4)

    def build_tab_play(self):
        # Disc image section
        f_disc = tk.Frame(self.tab_play, bg="#0a1728", highlightbackground="#0077b6", highlightthickness=1)
        f_disc.pack(fill=tk.X, padx=8, pady=8)

        self.lbl_disc_box = tk.Label(f_disc, text=self.tr("disc_box"), font=("Segoe UI", 9, "bold"),
                                     fg="#00e5ff", bg="#0a1728")
        self.lbl_disc_box.pack(anchor="w", padx=10, pady=(6, 2))

        self.lbl_disc = tk.Label(f_disc, text=self.tr("disc_label"), font=("Segoe UI", 9),
                                 fg="#ffffff", bg="#0a1728")
        self.lbl_disc.pack(anchor="w", padx=10, pady=(2, 2))

        f_disc_row = tk.Frame(f_disc, bg="#0a1728")
        f_disc_row.pack(fill=tk.X, padx=10, pady=(2, 4))

        self.ent_disc = tk.Entry(f_disc_row, font=("Segoe UI", 9), bg="#050d18", fg="#ffffff",
                                 insertbackground="#00e5ff", relief="solid", bd=1)
        self.ent_disc.insert(0, self.config_data.get("image_path", ""))
        self.ent_disc.pack(side=tk.LEFT, fill=tk.X, expand=True, ipady=4)

        self.btn_browse = tk.Button(f_disc_row, text=self.tr("browse"), font=("Segoe UI", 9, "bold"),
                                    fg="#00e5ff", bg="#0d2e4f", activebackground="#14487a",
                                    activeforeground="#ffffff", relief="flat", padx=12,
                                    cursor="hand2", command=self.browse_disc)
        self.btn_browse.pack(side=tk.LEFT, padx=(6, 0))

        self.lbl_disc_hint = tk.Label(f_disc, text=self.tr("disc_hint"), font=("Segoe UI", 8),
                                      fg="#6c8ca8", bg="#0a1728")
        self.lbl_disc_hint.pack(anchor="w", padx=10, pady=(2, 8))

        # Memory card section
        f_card = tk.Frame(self.tab_play, bg="#0a1728", highlightbackground="#0077b6", highlightthickness=1)
        f_card.pack(fill=tk.X, padx=8, pady=6)

        self.lbl_card_box = tk.Label(f_card, text=self.tr("card_box"), font=("Segoe UI", 9, "bold"),
                                     fg="#00e5ff", bg="#0a1728")
        self.lbl_card_box.pack(anchor="w", padx=10, pady=(6, 2))

        f_card_row = tk.Frame(f_card, bg="#0a1728")
        f_card_row.pack(fill=tk.X, padx=10, pady=(2, 4))

        self.lbl_card_status = tk.Label(f_card_row, text=self.get_card_status_text(),
                                        font=("Segoe UI", 9), fg="#ffb703", bg="#0a1728")
        self.lbl_card_status.pack(side=tk.LEFT, fill=tk.X, expand=True)

        self.btn_saves = tk.Button(f_card_row, text=self.tr("open_saves"), font=("Segoe UI", 8, "bold"),
                                   fg="#8ecae6", bg="#0d2e4f", activebackground="#14487a",
                                   activeforeground="#ffffff", relief="flat", padx=8, pady=2,
                                   cursor="hand2", command=self.open_saves_dir)
        self.btn_saves.pack(side=tk.LEFT, padx=(6, 0))

        self.lbl_card_desc = tk.Label(f_card, text=self.tr("card_desc"), font=("Segoe UI", 8),
                                      fg="#6c8ca8", bg="#0a1728")
        self.lbl_card_desc.pack(anchor="w", padx=10, pady=(2, 8))

        # Launch Big Play Button
        f_play = tk.Frame(self.tab_play, bg="#050d18")
        f_play.pack(fill=tk.BOTH, expand=True, padx=8, pady=12)

        self.btn_play = tk.Button(f_play, text=self.tr("btn_play"), font=("Impact", 22),
                                  fg="#000000", bg="#ff8800", activebackground="#ffa033",
                                  activeforeground="#000000", relief="flat", bd=0,
                                  cursor="hand2", command=self.on_play)
        self.btn_play.pack(fill=tk.X, ipady=12, pady=10)

    def build_tab_options(self):
        f_opts = tk.Frame(self.tab_options, bg="#0a1728", highlightbackground="#0077b6", highlightthickness=1)
        f_opts.pack(fill=tk.BOTH, expand=True, padx=8, pady=8)

        self.lbl_opt_display = tk.Label(f_opts, text=self.tr("opt_display_box"),
                                        font=("Segoe UI", 10, "bold"), fg="#00e5ff", bg="#0a1728")
        self.lbl_opt_display.pack(anchor="w", padx=14, pady=(10, 8))

        # Internal resolution
        row1 = tk.Frame(f_opts, bg="#0a1728")
        row1.pack(fill=tk.X, padx=14, pady=6)
        self.lbl_ires = tk.Label(row1, text=self.tr("opt_internal_res"), font=("Segoe UI", 9),
                                 fg="#ffffff", bg="#0a1728", width=24, anchor="w")
        self.lbl_ires.pack(side=tk.LEFT)
        self.cbo_ires = ttk.Combobox(row1, values=INTERNAL_RES_OPTIONS, state="readonly", width=34)
        ires_idx = self.config_data.get("internal_resolution", 0)
        self.cbo_ires.current(ires_idx if 0 <= ires_idx < len(INTERNAL_RES_OPTIONS) else 0)
        self.cbo_ires.pack(side=tk.LEFT)

        # Aspect ratio
        row2 = tk.Frame(f_opts, bg="#0a1728")
        row2.pack(fill=tk.X, padx=14, pady=6)
        self.lbl_aspect = tk.Label(row2, text=self.tr("opt_aspect"), font=("Segoe UI", 9),
                                   fg="#ffffff", bg="#0a1728", width=24, anchor="w")
        self.lbl_aspect.pack(side=tk.LEFT)
        self.var_aspect = tk.IntVar(value=self.config_data.get("aspect_ratio", 0))
        self.rb_4_3 = tk.Radiobutton(row2, text=self.tr("opt_aspect_4_3"), variable=self.var_aspect,
                                     value=0, bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                     activebackground="#0a1728", activeforeground="#00e5ff")
        self.rb_4_3.pack(side=tk.LEFT, padx=(0, 12))
        self.rb_16_9 = tk.Radiobutton(row2, text=self.tr("opt_aspect_16_9"), variable=self.var_aspect,
                                      value=1, bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                      activebackground="#0a1728", activeforeground="#00e5ff")
        self.rb_16_9.pack(side=tk.LEFT)

        # Window mode
        row3 = tk.Frame(f_opts, bg="#0a1728")
        row3.pack(fill=tk.X, padx=14, pady=6)
        self.lbl_wmode = tk.Label(row3, text=self.tr("opt_window_mode"), font=("Segoe UI", 9),
                                  fg="#ffffff", bg="#0a1728", width=24, anchor="w")
        self.lbl_wmode.pack(side=tk.LEFT)
        self.var_wmode = tk.IntVar(value=self.config_data.get("window_mode", 0))
        self.rb_win = tk.Radiobutton(row3, text=self.tr("opt_window_windowed"), variable=self.var_wmode,
                                     value=0, bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                     activebackground="#0a1728", activeforeground="#00e5ff")
        self.rb_win.pack(side=tk.LEFT, padx=(0, 8))
        self.rb_borderless = tk.Radiobutton(row3, text=self.tr("opt_window_borderless"), variable=self.var_wmode,
                                            value=1, bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                            activebackground="#0a1728", activeforeground="#00e5ff")
        self.rb_borderless.pack(side=tk.LEFT, padx=(0, 8))
        self.rb_fs = tk.Radiobutton(row3, text=self.tr("opt_window_exclusive"), variable=self.var_wmode,
                                    value=2, bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                    activebackground="#0a1728", activeforeground="#00e5ff")
        self.rb_fs.pack(side=tk.LEFT)

        # Window resolution
        row4 = tk.Frame(f_opts, bg="#0a1728")
        row4.pack(fill=tk.X, padx=14, pady=6)
        self.lbl_wres = tk.Label(row4, text=self.tr("opt_window_res"), font=("Segoe UI", 9),
                                 fg="#ffffff", bg="#0a1728", width=24, anchor="w")
        self.lbl_wres.pack(side=tk.LEFT)
        self.cbo_wres = ttk.Combobox(row4, values=WINDOW_RES_OPTIONS, state="readonly", width=34)
        wres_idx = self.config_data.get("window_resolution", 1)
        self.cbo_wres.current(wres_idx if 0 <= wres_idx < len(WINDOW_RES_OPTIONS) else 1)
        self.cbo_wres.pack(side=tk.LEFT)

        # VSync
        row5 = tk.Frame(f_opts, bg="#0a1728")
        row5.pack(fill=tk.X, padx=14, pady=6)
        self.var_vsync = tk.BooleanVar(value=bool(self.config_data.get("vsync", False)))
        self.chk_vsync = tk.Checkbutton(row5, text=self.tr("opt_vsync"), variable=self.var_vsync,
                                        bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                        activebackground="#0a1728", activeforeground="#00e5ff")
        self.chk_vsync.pack(side=tk.LEFT)

        # Unlock All
        row6 = tk.Frame(f_opts, bg="#0a1728")
        row6.pack(fill=tk.X, padx=14, pady=6)
        self.var_unlock = tk.BooleanVar(value=bool(self.config_data.get("unlock_all", False)))
        self.chk_unlock = tk.Checkbutton(row6, text=self.tr("opt_unlock"), variable=self.var_unlock,
                                         bg="#0a1728", fg="#ffffff", selectcolor="#050d18",
                                         activebackground="#0a1728", activeforeground="#00e5ff")
        self.chk_unlock.pack(side=tk.LEFT)

    def build_tab_controls(self):
        f_ctrl = tk.Frame(self.tab_controls, bg="#0a1728", highlightbackground="#0077b6", highlightthickness=1)
        f_ctrl.pack(fill=tk.BOTH, expand=True, padx=8, pady=8)

        self.lbl_ctrl_box = tk.Label(f_ctrl, text=self.tr("ctrl_box"), font=("Segoe UI", 10, "bold"),
                                     fg="#00e5ff", bg="#0a1728")
        self.lbl_ctrl_box.pack(anchor="w", padx=14, pady=(10, 8))

        self.cbo_ports = []
        ports = self.config_data.get("ports", ["keyboard", "none", "none", "none"])
        device_labels = ["ctrl_p1", "ctrl_p2", "ctrl_p3", "ctrl_p4"]

        for idx, plabel in enumerate(device_labels):
            row = tk.Frame(f_ctrl, bg="#0a1728")
            row.pack(fill=tk.X, padx=14, pady=6)

            lbl = tk.Label(row, text=self.tr(plabel), font=("Segoe UI", 9),
                           fg="#ffffff", bg="#0a1728", width=22, anchor="w")
            lbl.pack(side=tk.LEFT)

            cbo = ttk.Combobox(row, values=[
                self.tr("ctrl_device_keyboard"),
                self.tr("ctrl_device_auto"),
                self.tr("ctrl_device_none")
            ], state="readonly", width=32)
            cur = ports[idx] if idx < len(ports) else "none"
            if cur == "keyboard":
                cbo.current(0)
            elif cur == "none":
                cbo.current(2)
            else:
                cbo.current(1)
            cbo.pack(side=tk.LEFT)
            self.cbo_ports.append((lbl, cbo))

    def build_tab_credits(self):
        f_cred = tk.Frame(self.tab_credits, bg="#0a1728", highlightbackground="#0077b6", highlightthickness=1)
        f_cred.pack(fill=tk.BOTH, expand=True, padx=8, pady=8)

        self.lbl_cred_box = tk.Label(f_cred, text=self.tr("credits_box"), font=("Segoe UI", 10, "bold"),
                                     fg="#00e5ff", bg="#0a1728")
        self.lbl_cred_box.pack(anchor="w", padx=14, pady=(10, 8))

        self.txt_credits = tk.Label(f_cred, text=self.tr("credits_text"), font=("Segoe UI", 9),
                                    fg="#d9e6f2", bg="#0a1728", justify=tk.LEFT)
        self.txt_credits.pack(anchor="w", padx=14, pady=6)

    def get_card_status_text(self):
        card_file = os.path.join("saves", "MemoryCardA.card")
        lock_file = os.path.join("saves", "MemoryCardA.lock")
        if os.path.exists(lock_file):
            return self.tr("card_locked")
        if os.path.exists(card_file):
            return self.tr("card_detected")
        return self.tr("card_new")

    def toggle_language(self):
        self.cur_lang = "en" if self.cur_lang == "pt-BR" else "pt-BR"
        self.update_language()

    def update_language(self):
        self.btn_lang.config(text=self.tr("lang_btn"))
        self.lbl_title.config(text=self.tr("title"))
        self.lbl_subtitle.config(text=self.tr("subtitle"))
        self.notebook.tab(0, text=self.tr("tab_play"))
        self.notebook.tab(1, text=self.tr("tab_controls"))
        self.notebook.tab(2, text=self.tr("tab_options"))
        self.notebook.tab(3, text=self.tr("tab_credits"))

        # Play tab
        self.lbl_disc_box.config(text=self.tr("disc_box"))
        self.lbl_disc.config(text=self.tr("disc_label"))
        self.btn_browse.config(text=self.tr("browse"))
        self.lbl_disc_hint.config(text=self.tr("disc_hint"))
        self.lbl_card_box.config(text=self.tr("card_box"))
        self.lbl_card_status.config(text=self.get_card_status_text())
        self.btn_saves.config(text=self.tr("open_saves"))
        self.lbl_card_desc.config(text=self.tr("card_desc"))
        self.btn_play.config(text=self.tr("btn_play"))

        # Options tab
        self.lbl_opt_display.config(text=self.tr("opt_display_box"))
        self.lbl_ires.config(text=self.tr("opt_internal_res"))
        self.lbl_aspect.config(text=self.tr("opt_aspect"))
        self.rb_4_3.config(text=self.tr("opt_aspect_4_3"))
        self.rb_16_9.config(text=self.tr("opt_aspect_16_9"))
        self.lbl_wmode.config(text=self.tr("opt_window_mode"))
        self.rb_win.config(text=self.tr("opt_window_windowed"))
        self.rb_borderless.config(text=self.tr("opt_window_borderless"))
        self.rb_fs.config(text=self.tr("opt_window_exclusive"))
        self.lbl_wres.config(text=self.tr("opt_window_res"))
        self.chk_vsync.config(text=self.tr("opt_vsync"))
        self.chk_unlock.config(text=self.tr("opt_unlock"))

        # Controls tab
        self.lbl_ctrl_box.config(text=self.tr("ctrl_box"))
        device_labels = ["ctrl_p1", "ctrl_p2", "ctrl_p3", "ctrl_p4"]
        for idx, (lbl, cbo) in enumerate(self.cbo_ports):
            lbl.config(text=self.tr(device_labels[idx]))
            cur_idx = cbo.current()
            cbo.config(values=[
                self.tr("ctrl_device_keyboard"),
                self.tr("ctrl_device_auto"),
                self.tr("ctrl_device_none")
            ])
            if cur_idx >= 0:
                cbo.current(cur_idx)

        # Credits tab
        self.lbl_cred_box.config(text=self.tr("credits_box"))
        self.txt_credits.config(text=self.tr("credits_text"))

        # Footer
        self.lbl_status.config(text=self.tr("status_engine"))
        self.btn_save_settings.config(text=self.tr("btn_save"))

    def browse_disc(self):
        filetypes = [
            ("GameCube Disc Images", "*.iso *.ciso *.nkit.iso *.rvz"),
            ("ISO Images", "*.iso"),
            ("CISO Images", "*.ciso"),
            ("RVZ Images", "*.rvz"),
            ("All Files", "*.*")
        ]
        chosen = filedialog.askopenfilename(title=self.tr("disc_label"), filetypes=filetypes)
        if chosen:
            self.ent_disc.delete(0, tk.END)
            self.ent_disc.insert(0, chosen)

    def open_saves_dir(self):
        os.makedirs("saves", exist_ok=True)
        if sys.platform.startswith("linux"):
            subprocess.Popen(["xdg-open", "saves"])
        elif sys.platform == "darwin":
            subprocess.Popen(["open", "saves"])
        else:
            os.startfile("saves")

    def collect_config(self):
        ports = []
        for _, cbo in self.cbo_ports:
            idx = cbo.current()
            if idx == 0:
                ports.append("keyboard")
            elif idx == 1:
                ports.append("auto")
            else:
                ports.append("none")

        return {
            "version": 1,
            "vsync": bool(self.var_vsync.get()),
            "window_mode": int(self.var_wmode.get()),
            "window_resolution": max(0, self.cbo_wres.current()),
            "internal_resolution": max(0, self.cbo_ires.current()),
            "aspect_ratio": int(self.var_aspect.get()),
            "unlock_all": bool(self.var_unlock.get()),
            "language": self.cur_lang,
            "image_path": self.ent_disc.get().strip(),
            "keyboard_enabled": ("keyboard" in ports),
            "keyboard_port": ports.index("keyboard") if "keyboard" in ports else 0,
            "ports": ports,
            "keys": self.config_data.get("keys", DEFAULT_KEYS)
        }

    def on_save_button(self):
        cfg = self.collect_config()
        self.config_data = cfg
        save_config(cfg)
        messagebox.showinfo("Launcher", self.tr("saved_msg"))

    def on_play(self):
        cfg = self.collect_config()
        self.config_data = cfg
        save_config(cfg)

        disc = cfg.get("image_path", "").strip()
        binary = "./digimon_test"
        if not os.path.exists(binary):
            # Check build directory or fallback
            if os.path.exists("./digimon_test.exe"):
                binary = "./digimon_test.exe"
            elif os.path.exists("build_test/usability/Release/digimon_test.exe"):
                binary = "build_test/usability/Release/digimon_test.exe"

        if os.path.exists(binary):
            try:
                os.chmod(binary, 0o755)
            except Exception:
                pass
            try:
                with open(binary, "rb") as bf:
                    if bf.read(2) == b"MZ" and sys.platform != "win32":
                        msg = (
                            "O arquivo ./digimon_test é um executável de Windows (.exe) e não um binário nativo de Linux ELF (x86_64).\n\n"
                            "Baixe o pacote oficial de Linux compilado pelo GitHub Actions na aba Releases do projeto."
                            if self.cur_lang == "pt-BR" else
                            "The file ./digimon_test is a Windows executable (.exe), not a native Linux ELF binary.\n\n"
                            "Please download the official native Linux package built via GitHub Actions from the project Releases."
                        )
                        messagebox.showerror("Error", msg)
                        return
            except Exception:
                pass

        cmd = [binary, "--portable"]
        if disc:
            cmd += ["--disc", disc]
        if cfg.get("unlock_all", False):
            cmd += ["--unlock-all"]

        try:
            subprocess.Popen(cmd)
            self.destroy()
        except Exception as ex:
            messagebox.showerror("Error", f"Failed to start {binary}: {ex}")

def main():
    app = LinuxLauncher()
    app.mainloop()

if __name__ == "__main__":
    main()
