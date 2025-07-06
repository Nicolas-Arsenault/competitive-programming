![[Pasted image 20250624165936.png]]

## Requirements (~5 minutes)

Get a clear understanding of the system that you are being asked to design.

### 1) Functional Requirements

Users should be able to ... statement.
These are the core features of the system and should be discussed first with the interviewer.

("does the system need to do X?", "what would happen if Y?") to arrive at a prioritized list of core features.

For example, if you were designing a system like Twitter, you might have the following functional requirements:

- Users should be able to post tweets
    
- Users should be able to follow other users
    
- Users should be able to see tweets from users they follow
    

A cache meanwhile might have requirements like:

- Clients should be able to insert items
    
- Clients should be able to set expirations
    
- Clients should be able to read items

**ONLY TAKE TOP 3 MOST IMPORTANT REQUIREMENTS**

### 2) Non-functional Requirements
Non-functional requirements are statements about the system qualities that are important to your users. These can be phrased as "The system should be able to..." or "The system should be..." statements.

- The system should be highly availability, prioritizing availability over consistency
    
- The system should be able to scale to support 100M+ DAUs
    
- The system should be low latency, rendering feeds in under 200ms

it is important to put data (Ex: 200ms)

**We want only the top 3-5 non functional requirements**

Here is a checklist of things to consider that might help you identify the most important non-functional requirements for your system. You'll want to identify the top 3-5 that are most relevant to your system.

1. **CAP Theorem**: Should your system prioritize consistency or availability? Note, partition tolerance is a given in distributed systems.
    
2. **Environment Constraints**: Are there any constraints on the environment in which your system will run? For example, are you running on a mobile device with limited battery life? Running on devices with limited memory or limited bandwidth (e.g. streaming video on 3G)?
    
3. **Scalability**: All systems need to scale, but does this system have unique scaling requirements? For example, does it have bursty traffic at a specific time of day? Are there events, like holidays, that will cause a significant increase in traffic? Also consider the read vs write ratio here. Does your system need to scale reads or writes more?
    
4. **Latency**: How quickly does the system need to respond to user requests? Specifically consider any requests that require meaningful computation. For example, low latency search when designing Yelp.
    
5. **Durability**: How important is it that the data in your system is not lost? For example, a social network might be able to tolerate some data loss, but a banking system cannot.
    
6. **Security**: How secure does the system need to be? Consider data protection, access control, and compliance with regulations.
    
7. **Fault Tolerance**: How well does the system need to handle failures? Consider redundancy, failover, and recovery mechanisms.
    
8. **Compliance**: Are there legal or regulatory requirements the system needs to meet? Consider industry standards, data protection laws, and other regulations.

### 3) Capacity Estimation

We should ask the interviewer if we can skip this upfront and do it while design in when necessary

## Core Entities (~2 minutes)

Once you get into the high level design and have a clearer sense of exactly what state needs to update upon each request you can start to build out the list of relevant columns/fields for each entity.

For our Twitter example, our core entities are rather simple:

- User
    
- Tweet
    
- Follow

A couple useful questions to ask yourself to help identify core entities:

- Who are the actors in the system? Are they overlapping?
    
- What are the nouns or resources necessary to satisfy the functional requirements?

## API or System Interface (~5 minutes)

**RESTful API**: The standard communication constraints of the internet. Uses HTTP verbs (GET, POST, PUT, DELETE) to perform CRUD operations on resources.

**GraphQL API**: A newer communication protocol that allows clients to specify exactly what data they want to receive from the server.

**Wire Protocol**: If you're communicating over websockets or raw TCP sockets, you'll want to define the wire protocol. This is the format of the data that will be sent over the network, usually in the format of messages.


Most of the time its going to be RESTFULL Unless we need clients to fetch ONLY the requested data (GRAPHQL)

ex for twitter:

`POST /v1/tweet body: {   "text": string } GET /v1/tweet/:tweetId -> Tweet POST /v1/follow/:userId GET /v1/feed -> Tweet[]`

Do not put userId or auth stuff in the body of a post. Use the auth token in the request header.

## Data Flow (5 minutes) Optional

it can be helpfull to describe the high level sequence of actions or processes

we usually use a list format:

For a web crawler, this might look like:

1. Fetch seed URLs
    
2. Parse HTML
    
3. Extract URLs
    
4. Store data
    
5. Repeat

## High Level Design (~10-15 minutes)

Boxes and arrows that represent the components of the system and how they interact

The [Key Technologies](https://www.hellointerview.com/learn/system-design/in-a-hurry/key-technologies) section will give you a good sense of the most common components you'll need to know.


Ask your recruiter what software you'll be using for your interview and practice with it ahead of time. You don't want to be fumbling with the software during your interview.

Your primary goal is to design an architecture that satisfies the API you've designed and, thus, the requirements you've identified

you should be talking through your thought process with your interviewer.

Follow the data flow and document, When it hits the DB, design the columns for each entity

![[Pasted image 20250625210517.png]]

![[Pasted image 20250625210525.png]]

![[Pasted image 20250625210533.png]]![[Pasted image 20250625210540.png]]

## Deep Dives (~10 minutes)
Now that you have a high-level design in place you're going to use the remaining 10 or so minutes of the interview to harden your design by (a) ensuring it meets all of your non-functional requirements (b) addressing edge cases (c) identifying and addressing issues and bottlenecks and (d) improving the design based on probes from your interviewer.

one of our non-functional requirements for Twitter was that our system needs to scale to >100M DAU. We could then lead a discussion oriented around horizontal scaling, the introduction of caches, and database sharding -- updating our design as we go. Another was that feeds need to be fetched with low latency. In the case of Twitter, this is actually the most interesting problem. We'd lead a discussion about fanout-on-read vs fanout-on-write and the use of caches.