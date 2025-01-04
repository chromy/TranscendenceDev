# Transcendence clang build

The aim of this repo is to maintain a downstream clang build of
[Transcendence](https://github.com/kronosaur/TranscendenceDev) the
incomparable [space roguelike](https://transcendence.kronosaur.com)
in development since [2003](https://web.archive.org/web/20031209010545/http://www.neurohack.com/Transcendence/Version0.70.html).

Originally distributed as freeware by solo-developer George Moromisato
the core engine of Transcendence was open-sourced circa 2012 and the current
official [unified repo](https://github.com/kronosaur/TranscendenceDev) stood up in 2015.

Transcendence is a x86 Windows app using DirectX (fairly directly,
Transcendence makes minimal use of the GPU) built with MSVC.

The initial goal is to:
- Maintain cross compilation builds from {Linux/x86_64, Mac/arm64, Mac/x86_64} to Windows/x86
- Upstream changes to the official repo where possible.

Making it possible to build Transcendence on other popular OSs (Linux, Mac) using a familiar toolchain on those platforms (clang):
- Widens the pool of potential contributors
- Paves the way for native ports and similar pro

## Requirements

Most dependencies will be downloaded for you by the `tools/fetch`
script however you will need to install the following yourself:

- `git`
- `python`
- `wine` (if you wish to run the Windows binaries on Linux/Mac)

## Build

The minimal instructions to get started:

```bash
git clone https://github.com/chromy/TranscendenceDev.git
cd TranscendenceDev
git checkout clang
./tools/fetch
./tools/gn gen --args='target_os="win" target_cpu="x86"' out/r
./tools/ninja -C out/r
wine out/r/unittests
```

Breaking those steps down with explanations:

Download the repository:
```bash
git clone https://github.com/chromy/TranscendenceDev.git
cd TranscendenceDev
```

The `master` branch tracks [kronosaur/TranscendenceDev/master] the `clang`
branch contains the clang build, CI, this README, etc.
```bash
git checkout clang
```

Download build dependencies. This downloads:
- the Windows SDK / sysroot
- clang (to)
- gn/ninja (buildtools similar to make/cmake/Bazel)
- etc

```bash
./tools/fetch
```

Generate an out directory (`out/r`) targeting `windows/x86`.
The `host_os` and `host_cpu` args are set automatically.

If you are familiar with autotools this is simialr to the `./configure` step
in that it is a one-off step TKTK

```bash
./tools/gn gen --args='target_os="win" target_cpu="x86"' out/r
```

TKTK
Equivilent 
```bash
./tools/ninja -C out/r
```

TKTK
```bash
wine out/r/unittests
```

## History of ports
https://github.com/GambitDash/Transport


