# Creating backdoor using `setuid`

Alright folks, by now, you should be familiar with the common `drwxrwxrwx+` structure. Anyway, I'm going to explain:

1. The first character, in this case `d`, stands for the file type. 
2. The following three characters, in this case `rwx` stand for the user permissions. IE the owner permissions.
3. The following three characters for groups.
4. The following three characters for everyone else.
5. The last character for special file attributes that even I don't know in depth about.

We are going to talk about regular files, so we have the first char `-` instead of `d`.

Then instead of `x` for the user, we are going to use a special permission `s` which allows the current user to get an instance of the owner of the file. For example,

    [batman@dc: setuid]$ ls -l      
    -rwsr-xr-x 1 root  root  120 Oct 28 09:54 executor

If you run `./executor` as a normal user, you will notice that executor is running as a root user. That's the magic of `s` permission.

## This project
In this project, I have created the backdoor.c in order to allow launching any non-bash-script file as root user(Bash is disabled to accept `s` for root user by defautl). To check whether this is working, run the following commands:

    sudo gcc backdoor.c -o backdoor
    sudo chmod u+s backdoor

Place your backdoor file anywhere on the server. To launch the backdoor, type the following:
`./backdoor <program_name> # launches <program_name> under root user`


## Debugging
**I can't run bash files.**: No you can't. It's disabled on most distros by default for security reasons. Try using alternatives like `/usr/bin/python`

**File not executing**: Did you enter the full file path?i.e, `/usr/bin/python` instead of `python`?

**Arguments not passing**: See backdoor.c for the reasons.
