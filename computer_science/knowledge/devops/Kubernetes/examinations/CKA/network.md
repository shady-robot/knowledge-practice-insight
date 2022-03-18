# Network namespaces

```shell
ip netns add red
ip netns add blue
ip netns

# View the interfaces in host
ip link

# View the interfaces in isolated namespace
ip netns exec red ip link
ip -n red link/arp/route

# Adding virtual cable with two interfaces
ip link add veth-red type veth peer name veth-blue

# Attach each interface to appropriate namespace
ip link set veth-red netns red
ip link set veth-blue netns blue

# Assign ip address to namespaces
ip -n red addr add 192.68.15.1 dev veth-red
ip -n blue addr add 192.68.15.2 dev veth-blue

ip -n red link set veth-red up
ip -n blue link set veth-blue up

ip netns exec red ping 192.168.15.2

ip netns exec red arp
```

## Linux bridge

```shell
ip link add v-net-0 type bridge
ip link
ip link set dev v-net-0 up

ip link add veth-red type veth peer name veth-red-br
ip link add veth-red blue veth peer name veth-blue-br

ip link set veth-red netns red
ip link set veth-red-br master v-net-0

ip link set veth-blue netns blue
ip link set veth-blue-br master v-net-0

ip -n red addr add 192.168.15.1 dev veth-red
ip -n blue addr add 192.168.15.2 dev veth-blue

ip addr add 192.168.15.5/24 dev v-net-0

ip netns exec blue ip route add 192.168.1.0/24 via 192.168.15.5
```
