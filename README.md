# DNS

## gdb debugger (ubuntu)

```bash
sudo apt install gdb -y
```

Using gdb

```bash
# gdb <output file>
gdb dns_server.out
```

for source view type:

```bash
layout src
```

```bash
start                   # to start the debugger
refresh                 # to refresh the screen
n+ Enter                # to go to next line
print <variable name>   # print value in variable
exit                    # to exit
```
