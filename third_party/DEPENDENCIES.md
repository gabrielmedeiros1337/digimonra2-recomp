# Build dependencies

`recomp-deps/` is a minimal, byte-identical source snapshot from the validated
local build. `dependency_manifest.json` records original repositories, commits
and per-file SHA-256 values. Run `python tools/verify_dependencies.py` to check it.

The production build does not fetch or initialize submodules. This removes the
dependency on unpublished local commits and avoids downloading unrelated emulator
components. The historical `ModernGekko-Template/` checkout is left intact locally,
ignored by Git, and is no longer an input to CMake. The frozen tag/build remains
unchanged. No CPU, GX, timing or chunk implementation was modified for this move.

Included components retain their upstream notices and licenses:

- DolRecomp: `recomp-deps/DolRecomp/LICENSE`; includes the existing validated CPU fixes.
- Dolphin build files/data: `recomp-deps/dolphin/COPYING`.
- bzip2: `recomp-deps/dolphin/Externals/bzip2/bzip2/LICENSE`.
- liblzma: `recomp-deps/dolphin/Externals/liblzma/COPYING`.
- picojson: `recomp-deps/dolphin/Externals/picojson/LICENSE`.
- Zstandard: `recomp-deps/dolphin/Externals/zstd/zstd/LICENSE` and `COPYING`.
- xxHash: `recomp-deps/dolphin/Externals/xxhash/xxHash/LICENSE`.
- SDL2 2.32.0 development headers and x64 release binaries: `SDL2/LICENSE.txt`.

Codec/source subsets contain the files actually used by this CMake build;
unrelated emulator backends, tests, media, Qt, FFmpeg and platform SDKs are omitted.
The SDL DLL/import libraries are redistributable dependency files, not game data.
