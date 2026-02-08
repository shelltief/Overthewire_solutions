# [Bandit17->18](https://overthewire.org/wargames/bandit/bandit18.html)

## Level Goal

There are 2 files in the homedirectory: **passwords.old** and **passwords.new**. 
The password for the next level is in passwords.new and is the only line that has been changed between 
passwords.old and passwords.new.

NOTE: if you have solved this level and see ‘Byebye!’ when trying to log into bandit18, this is related to the next level, bandit19.

## Commands useful to solve the level

- [diff](https://www.gnu.org/software/diffutils/manual/diffutils.html)

## Helpful Reading Material

- [diff Wikipedia page](https://en.wikipedia.org/wiki/Diff)

## Where to start?

We know that there are two files in our directory that we can view with the `ls` command : **passwords.old** and **passwords.new**, we are going to need 
to output the difference between those two files. We know that the new password is the line that has been updated in the **passwords.new** file.


??? note "Part 1 : Output the diff of the files"

    We want to see the differences between both files printed to standard output.

    ??? tip "Hint"

        By looking at the [diff](https://man7.org/linux/man-pages/man1/diff.1.html) man page,
        can you figure out how to use the `diff(1)` utility to output the differences between these two files?

    ??? success "Solution"

        To do so, we simply need to run the following command :
        ```bash
        diff passwords.old passwords.new
        ```
        The lines that are different in passwords.old (the first argument) will appear prefixed by the
        symbol `<` while the lines different in passwords.new will appear prefixed by a `>`.
        The password is the line that is different in **passwords.new**

??? note "Part 2 : Making diff output a bit more readable"

    Right now, we need to remember that the different lines from the first file will be prefixed by `<`
    and the ones from the second file by `>`. Let's find a way to make the output more readable so
    that we don't need to remember this information.

    ??? tip "Hint"

        Looking more deeply into the [diff](https://man7.org/linux/man-pages/man1/diff.1.html)
        man page, can you figure out a way to make the output more readable ?

        *They are a lot more than one answer.*

    ??? success "Solution"

        For example, one could use the option `-u` to print a string at the beginning of the
        `diff` output which will look like the one below :
        ```bash
        --- passwords.old	2023-10-05 06:19:27.827277353 +0000
        +++ passwords.new	2023-10-05 06:19:27.835277371 +0000
        ```
        which means that all the lines from passwords.old will be prefixed by `-` and the lines
        from passwords.new will be prefixed by `+`. The `diff -u` output will be the following :
        ```bash
        --- passwords.old	2023-10-05 06:19:27.827277353 +0000
        +++ passwords.new	2023-10-05 06:19:27.835277371 +0000
        @@ -39,7 +39,7 @@
         WFB9ezoSnb146RUbbX6d9Yx2sU46Q8Ax
         JFkUvvpfLmE7KBkAEePwZndBr33oFzh8
         wDn38KGxWKk7dp39odF7fWLT6aljqEsK
        -old_password
        +new_password
         RKMlN2JZydt4j5rQjJt07GgNqtgnq8dw
         nssByafsRMwebfyRhMWKSqX39xF1l4Hr
         ZlUzDUTd4faumV8wCtJ4CHA788tySKDO
        ```
        We can then use the new password to go to the following level.

??? note "Full Solution"

    1. `diff passwords.old passwords.new` to output the differences between the two files and retrieve the new password from the passwords.new file.

You can now jump to the [next level](./bandit18.md)
