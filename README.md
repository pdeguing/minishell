# minishell
"﻿The objective of this project is for you to create the simplest start of a shell script. Shell is beautiful! Isn’t there a famous saying? “As beautiful as Shell?” Thanks to all the shell projects, you will connect with the infinite power of Mankind Intelligence (Not even sure that you deserve it, but I have been forced to do so, so here we are. . . )."


### BUGS TO FIX

* Fixed: by removing the prefix PATH= on the first string to try... PATH not working if set to /bin, try other similar, it works only when we use the full original PATH
* Fixed: ft_strccmp was not implemented correctly... setenv PATH will add a new PATH instead of replacing the existing one
* SEGFAULT WHEN CTRL+D 
* Fixed: resetting signal after child process terminate... CTRL+C DOES NOT PUT PROMPT BACK IF DONE AFTER PROGRAM EXE
* Fixed: Leaks: cd / unsetenv
* Fixed: usage displays twice if 2 args in setenv
* Fixed: Segfault if echo non-existent var 
* Fixed: Leaks if echo non-existent var
* Should print $ if only $


### TO DO

- [x] check builtins
- [x] create a function get_value to get value of env var
- [x] manage extensions
- [x] bonuses
- [ ] strsplit multiple characters (add TAB)
