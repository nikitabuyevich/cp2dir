## cp2dir

Copy a list of files to another directory.

Meant to be used as a post-build step/event to move compiled files easily.

Usage:

```bash
  -h [ --help ]                  Display usage.
  -f [ --files ] list of strings List of files to copy contents from. Must be a
                                 full path.
  -d [ --dir ] string            Destination directory to copy contents to. 
                                 Must be a full path.
```
  
Example:
```bash
cp2dir.exe 
-f 
D:/dev/foo/bin/foo/Debug/Win32/foo.dll 
D:/dev/bar/bin/bar/Debug/Win32/bar.dll 
-d
D:/dev/foobar/dist
```

