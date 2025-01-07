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
- [x] Create a clang build of Transcendence
- [ ] Maintain cross compilation builds from {Linux/x86_64, Mac/arm64, Mac/x86_64} to Windows/x86
- [ ] Upstream changes to the official repo where possible.

The idea is that making it possible to build Transcendence on other popular OSs (Linux, Mac) using a familiar toolchain on those platforms (clang):
- Widens the pool of potential contributors to Transcendence
- Paves the way for native ports and similar projects

## Demo
[![Cross compiling demo](http://img.youtube.com/vi/NHef--LcI_k/0.jpg)](http://www.youtube.com/watch?v=NHef--LcI_k "Cross compiling Transcendence with clang on MacOS")

[Video demo](https://youtu.be/NHef--LcI_k)


## Requirements

Most dependencies will be downloaded for you by the `tools/fetch`
script however you will need to install the following yourself:

- `git`
- `python`
- `curl`
- `wine` (if you wish to run the Windows binaries on Linux/Mac)

## Build

The minimal instructions to get started with the `clang` build:

```bash
git clone https://github.com/chromy/TranscendenceDev.git
cd TranscendenceDev
git checkout clang
./tools/fetch
./tools/gn gen --args='target_os="win" target_cpu="x86"' out/r
./tools/ninja -C out/r
wine out/r/unittests
wine out/r/game/Transcendence.exe
```

Breaking those steps down with explanations:

Download the repository:
```bash
git clone https://github.com/chromy/TranscendenceDev.git
cd TranscendenceDev
```

The `master` branch tracks [kronosaur/TranscendenceDev/master](https://github.com/kronosaur/TranscendenceDev/tree/master) the `clang`
branch contains the clang build, CI, this README, etc.
```bash
git checkout clang
```

Download build dependencies. This script downloads:
- the Windows SDK / sysroot
- `clang` (we vendor a fixed compiler version for consistency)
- `gn`/`ninja` (buildtools similar to make/cmake/Bazel)
- etc

```bash
./tools/fetch
```

Generate an out directory (`out/r`) targeting `windows/x86` using `gn`.
The `host_os` and `host_cpu` args are set automatically.
If you are familiar with autotools this is similar to the `./configure` step
in that it is a one-off step which creates a lower level description of
the build.


```bash
./tools/gn gen --args='target_os="win" target_cpu="x86"' out/r
```

Now build everything using `ninja`. [ninja](https://ninja-build.org/) is similar to `make`.

```bash
./tools/ninja -C out/r
```

There is a small suite of smoke tests which try to build, link,
and (where feasible) exercise the various Transcendence components:
```bash
wine out/r/unittests
```

Finally run `Transcendence` itself:
```bash
wine out/r/game/Transcendence.exe
```

## Contributing

If you wish to contribute to the official Transcendence repository see [here](https://github.com/kronosaur/TranscendenceDev).
If you wish to help with the `clang` build see [CONTRIBUTING.md](CONTRIBUTING.md).


## A brief history of attempted ports

- https://github.com/GambitDash/Transport
