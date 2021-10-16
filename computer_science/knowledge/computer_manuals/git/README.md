# Git

Git is a free and open source distributed version control system designed to
handle everything from small to very large projects with speed and efficiency.

## sync problem with file with lower case and upper case

If you need to commit files renaming, just capitalization, and you have a
problems with staging/commiting, as option

1. Change capitalization of "file" name and add "1" to the end (or other symbol)
2. Stage (without commit) = result "File1" - renaming files
3. Remove "1" from the end
4. Stage (without commit) = result "File" - renaming files (only capitalization
   now)
5. Do commit.

## References

* [upper-lower case problem with file](https://github.com/isaacs/github/issues/1520)
