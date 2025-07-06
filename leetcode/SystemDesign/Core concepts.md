## Scaling<
![[Pasted image 20250629192844.png]]

When horizontal scaling is the right solution, you'll need to consider how to distribute work across your machines. Most modern systems use a technique called ["Consistent Hashing"](https://www.hellointerview.com/learn/system-design/deep-dives/consistent-hashing) to distribute work across a set of machines - this is a technique that arranges both data and machines in a circular space called a "hash ring", allowing you to add or remove machines with minimal data redistribution.

### Work Distribution

Work distribution needs to try to [keep load on the system as even as possible](https://brooker.co.za/blog/2024/01/18/scalability.html).

### Data Distribution

If your system design problem involves geography, there's a good chance you have the option to partition by some sort of REGION_ID

Inherently, horizontal scaling on data introduces _synchronization challenges_. You're either reading and writing data to a shared database which is a network hop away (≈ 1-10ms, ideally) or you're keeping multiple redundant copies across each of your servers. This means race conditions and consistency challenges! Most database systems are built to resolve some of the these problems directly (e.g. by using transactions). In other cases, you may need to use a [Distributed Lock](https://www.hellointerview.com/learn/system-design/in-a-hurry/key-technologies#distributed-lock). Regardless, you'll need to be prepared to discuss how you're going to keep your data [Consistent](https://www.hellointerview.com/learn/system-design/in-a-hurry/core-concepts#consistency).

## [CAP Theorem](https://www.hellointerview.com/learn/system-design/deep-dives/cap-theorem)

fundamental concept in distributed systems that states you can only have two of three properties: Consistency, Availability, and Partition tolerance

Since network failure is inevitable, this means choosing between consistency and availability

Choosing consistency means that all nodes in your system will see the same data at the same time. When a write occurs, all subsequent reads will return that value, regardless of which node they hit. However, during a network partition, some nodes may become unavailable to maintain this consistency guarantee.

On the other hand, opting for availability means that every request will receive a response, even during network partitions. The tradeoff is that different nodes may temporarily have different versions of the data, leading to inconsistency. The system will eventually reconcile these differences, but there's no guarantee about when this will happen.

In a system design interview, availability should be your default choice. You only need strong consistency in systems where reading stale data is unacceptable.

Examples of systems that require strong consistency include:

- Inventory management systems, where stock levels need to be precisely tracked to avoid overselling products
    
- Booking systems for limited resources (airline seats, event tickets, hotel rooms) where you need to prevent double-booking
    
- Banking systems where the balance of an account must be consistent across all nodes to prevent fraud
    

The key characteristic of these systems is that any inconsistency, even temporary, could lead to significant business or technical problems.


## Locking

when we lock access to a ressource to prevent race conditions. we want the lock to be as precise as possible : ex on the user line and not on the table. we want the duration to be as optimised as possible. If we estimate the ressource wont be accessed too much or that consistency might not be a priority, we can use an Optimistic Concurrency approach:

![[Pasted image 20250629200801.png]]