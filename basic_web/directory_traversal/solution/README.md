1. Files served by the searching feature are by default in the `static` directory, we can imagine that the code looks something like: 
```
return ("./static/" + user_input)
```
2. Since the user_input is not sanitized, we can use a path traversal attack to access files outside of the `static` directory by using `../` to go up a directory.
3. From the challenge description, we know that the objective is to read the `app.py` file, which is up by one directory. We can do this by entering `../app.py` into the search bar.
4. The flag is a variable in the `app.py` file.
```

Flag: ISC2CTF{Tr@VeR$Ing_THe_d!r3c7ORIEs}