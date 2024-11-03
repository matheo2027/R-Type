# R-Type Network Protocol Documentation

## Message Types

The protocol uses an enumeration `messageType` to define different types of network messages:

```cpp
enum messageType
{
    CONNECT,        // Client connection request
    DISCONNECT,     // Client disconnection
    ENTITY_CREATE,  // Entity creation
    ENTITY_DESTROY, // Entity destruction
    MOVE,          // Entity movement
    KEY,           // Keyboard input
    MOUSE          // Mouse input
}
```

## Message Formats

### CONNECT
- **Client → Server**: Empty packet with CONNECT type
- **Server → Client**: CONNECT type + Entity ID

### DISCONNECT
- **Client → Server**: DISCONNECT type + Client ID
- **Server → Client**: DISCONNECT type + Client ID

### ENTITY_CREATE
- **Server → Client**: 
  - Type: ENTITY_CREATE
  - Entity ID
  - Position X
  - Position Y
  - Texture path

### ENTITY_DESTROY
- **Server → Client**:
  - Type: ENTITY_DESTROY
  - Entity ID

### MOVE
- **Server → Client**:
  - Type: MOVE
  - Entity count
  - For each entity:
    - Entity ID
    - Position X
    - Position Y

### KEY
- **Client → Server**:
  - Type: KEY
  - Client ID
  - Up state (bool)
  - Down state (bool)
  - Left state (bool)
  - Right state (bool)
  - Space state (bool)

### MOUSE
- **Client → Server**:
  - Type: MOUSE
  - Client ID
  - Mouse X position
  - Mouse Y position
  - Left button state (bool)
  - Right button state (bool)