# DirectX 5 Redocumentation
A redocumentation of DirectX 5, brought to you by a bunch of Infomaniacs.

## Progress

A complete file is considered to have all of it's documentation transferred, and ideally its parameters, return values, remarks, see-alsos, and if possible, any structure offsets.

- [ ] d3d.h
- [ ] d3dcaps.h

- [ ] d3drm.h
- [ ] d3drmdef.h
- [ ] d3drmobj.h
- [ ] d3drmwin.h

- [ ] d3dtypes.h
- [ ] ddraw.h
- [ ] dinput.h
- [ ] dplay.h
- [ ] dplobby.h
- [ ] [dsetup.h](https://github.com/orgs/mslibredoc/projects/1?pane=issue&itemId=35371687) - in progress
- [ ] dsound.h
- [ ] dvp.h
- [ ] fastfile.h

Possibly, code samples/tutorial sections (like, "Using the DirectXSetup Function") may be added for the purpose of a full doc restoration.

## Why?
Microsoft tends to remove documentations for old versions of their libraries. When decompiling/reverse engineering a game, it can be tricky to understand the data structures and functions when working with DirectX code.

The SDK does contain documentation in old Word and Windows Help files. These can be a pain to deal with, especially if you don't have Office.

Using Doxygen, the goal of this project is to annotate the header files to try to document as much of the code as possible through old media/books, translating and moving the documentation from the old files into Doxygen-friendly comments, and whatnot. Hopefully this will serve as reference for future decompilation projects using DX 5, especially if a state can be reached where the offsets of members in a data structure are documented.
