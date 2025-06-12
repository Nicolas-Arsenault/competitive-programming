# APIS Protocols

## RESTful

- Flexible
- Not most performant
- TCP
- JSON Serialization

## GraphQL

- Where frontend needs to iterate and adjust quickly
- Query backend for data they only need
- Can be a source of latency/complexity
- Good for Flexibility

## gRPC

- High performance
- Good for between services communication
- Not for public facing

## WebSockets
- RealTime bidirectional
- High frequency, persistent
- Like games

## SSE

- When we want clients to get notification as soon as the event happens
- ex: a bidding app
- Realtime update

## WebRTC
- Peer to peer
- UDP
- Audio/calling, collaborative apps
- Bounce server
- Might have problem bc of NAT

# Load Balancers

## Client side
- DNS
- Redis Cluster
- Not lots of clients 
- When we can tolerate update delays (Bc of DNS TTL)
- Query from server registry

## Hardware
- Layer 4
- Faster
- Good for persistent connections

## Software
- Layer 7
- Slower
- Access to HTTP Content
- More intelligent routing

Algorithms:
- **Round Robin**: Requests are distributed sequentially across servers
    
- **Random**: Requests are distributed randomly across servers
    
- **Least Connections**: Requests go to the server with the fewest active connections
    
- **Least Response Time**: Requests go to the server with the fastest response time
    
- **IP Hash**: Client IP determines which server receives the request (useful for session persistence)

Real world implementations:

-  **Hardware Load Balancers**: Physical devices like F5 Networks BIG-IP
    
- **Software Load Balancers**: HAProxy, NGINX, Envoy
    
- **Cloud Load Balancers**: AWS ELB/ALB/NLB, Google Cloud Load Balancing, Azure Load Balancer