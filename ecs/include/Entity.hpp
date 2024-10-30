/**
 * @file ecs.hpp
 * @brief Header file defining the Entity type in the ECS (Entity-Component-System) architecture.
 *
 * This file contains the definition of the Entity type used in the ECS framework.
 * An Entity represents a unique identifier for game objects within the ECS.
 *
 * @namespace ecs
 * The ecs namespace contains all the definitions related to the Entity-Component-System architecture.
 *
 * @typedef Entity
 * A type representing an entity in the ECS framework. It is defined as an unsigned integer,
 * allowing for a wide range of unique identifiers.
 */

#pragma once

namespace ecs
{

typedef unsigned int Entity;

}
