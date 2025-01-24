# R-Type Network Protocol Documentation

## Introduction
This document provides an in-depth explanation of the network protocol used in R-Type. The protocol enables real-time communication between clients (players) and the server, ensuring that all game events and entity states are synchronized effectively. It relies on predefined message types, each with a specific structure, to handle various tasks such as player connections, movement updates, and entity management.

The protocol adopts a client-server architecture:
- **Clients** send input data (keyboard, mouse, or connection requests) to the server.
- **Server** processes the input, updates the game state, and broadcasts the results (e.g., entity positions, creations, or destructions) to all connected clients.

## Message Types
The protocol defines an enumeration called `messageType`, which categorizes all possible network messages. These messages allow the server and clients to communicate specific actions or events in the game.

### Enumeration Definition
```cpp
enum messageType
{
    CONNECT,        // Client connection request
    DISCONNECT,     // Client disconnection
    ENTITY_CREATE,  // Notification of a new entity creation
    ENTITY_DESTROY, // Notification of an entity destruction
    MOVE,           // Position updates for entities
    KEY,            // Keyboard input from client
    MOUSE           // Mouse input from client
}
```

### Message Type Details
Each message type corresponds to a specific game action or event. Below is a detailed explanation of each type:

- **CONNECT**: Establishes a connection between the client and server. The server assigns a unique entity ID to the client to represent it in the game.
- **DISCONNECT**: Handles the termination of a client’s session, ensuring the server removes the client’s entity and notifies others.
- **ENTITY_CREATE**: Used by the server to notify all clients about the creation of a new entity, including its initial properties such as position and texture.
- **ENTITY_DESTROY**: Informs clients about the removal of an entity, ensuring all players stay synchronized.
- **MOVE**: Sends updated positions of entities from the server to clients, allowing clients to render the game world accurately.
- **KEY**: Transmits the state of the client’s keyboard inputs (e.g., movement keys or actions) to the server for processing.
- **MOUSE**: Sends the state of the client’s mouse inputs, including cursor position and button presses, to the server.

## Message Formats
Each message type follows a strict format, defining the structure and data exchanged between the client and server. These formats ensure consistency and reliability in communication.

### CONNECT
- **Purpose**: Establish a connection between a client and the server.
- **Flow**:
  - Client → Server: Sends a connection request.
  - Server → Client: Responds with a unique `Entity ID` to identify the client in the game.
- **Structure**:
  - **Client → Server**:
    - Type: `CONNECT`
    - Data: None (empty packet).
  - **Server → Client**:
    - Type: `CONNECT`
    - Data:
      - `Entity ID` (integer): A unique identifier for the client.

### DISCONNECT
- **Purpose**: Notify the server or clients of a disconnection.
- **Flow**:
  - Client → Server: Notifies the server of the disconnection.
  - Server → Client: Broadcasts the disconnection to other clients.
- **Structure**:
  - **Client → Server**:
    - Type: `DISCONNECT`
    - Data:
      - `Client ID` (integer): The identifier of the disconnecting client.
  - **Server → Client**:
    - Type: `DISCONNECT`
    - Data:
      - `Client ID` (integer): The identifier of the disconnected client.

### ENTITY_CREATE
- **Purpose**: Inform clients about the creation of a new entity in the game.
- **Flow**:
  - Server → Client: Broadcasts the creation of an entity to all connected clients.
- **Structure**:
  - Type: `ENTITY_CREATE`
  - Data:
    - `Entity ID` (integer): Unique identifier for the new entity.
    - `Position X` (float): Initial X-coordinate of the entity.
    - `Position Y` (float): Initial Y-coordinate of the entity.
    - `Texture path` (string): Path to the texture resource used to render the entity.

### ENTITY_DESTROY
- **Purpose**: Notify clients about the removal of an entity from the game.
- **Flow**:
  - Server → Client: Broadcasts the destruction of an entity.
- **Structure**:
  - Type: `ENTITY_DESTROY`
  - Data:
    - `Entity ID` (integer): Identifier of the entity to be destroyed.

### MOVE
- **Purpose**: Update the positions of entities in the game world.
- **Flow**:
  - Server → Client: Sends position updates for one or more entities.
- **Structure**:
  - Type: `MOVE`
  - Data:
    - `Entity count` (integer): Number of entities being updated.
    - For each entity:
      - `Entity ID` (integer): Identifier of the entity.
      - `Position X` (float): Updated X-coordinate.
      - `Position Y` (float): Updated Y-coordinate.

### KEY
- **Purpose**: Transmit keyboard input from a client to the server.
- **Flow**:
  - Client → Server: Sends the current state of movement or action keys.
- **Structure**:
  - Type: `KEY`
  - Data:
    - `Client ID` (integer): Identifier of the client sending the input.
    - `Up state` (bool): State of the "Up" key (pressed or not).
    - `Down state` (bool): State of the "Down" key.
    - `Left state` (bool): State of the "Left" key.
    - `Right state` (bool): State of the "Right" key.
    - `Space state` (bool): State of the spacebar key.

### MOUSE
- **Purpose**: Transmit mouse input from a client to the server.
- **Flow**:
  - Client → Server: Sends the current mouse position and button states.
- **Structure**:
  - Type: `MOUSE`
  - Data:
    - `Client ID` (integer): Identifier of the client sending the input.
    - `Mouse X position` (float): X-coordinate of the mouse cursor.
    - `Mouse Y position` (float): Y-coordinate of the mouse cursor.
    - `Left button state` (bool): State of the left mouse button.
    - `Right button state` (bool): State of the right mouse button.

## Conclusion
The R-Type network protocol is meticulously designed to enable smooth, real-time communication between the server and multiple clients. By adhering to the structured message types and formats described above, the protocol ensures consistency, efficiency, and synchronization in a multiplayer gaming environment.
