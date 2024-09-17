#pragma once

#include <memory>
#include <vector>

#include <glm/vec2.hpp>

#include "../Renderer/Vulkan/VulkanBuffer.h"

#define CHUNK_SIZE 64

namespace drive
{
struct Chunk
{
    glm::ivec2 position;
    glm::vec2  worldPosition;
    glm::vec2  worldCenter;

    std::vector<TerrainVertex> vertices;
    std::vector<Index>         indices;

    std::shared_ptr<VulkanBuffer<TerrainVertex, VertexBuffer>> vertexBuffer;
    std::shared_ptr<VulkanBuffer<Index, IndexBuffer>>          indexBuffer;

    Chunk(glm::ivec2 pos)
    {
        position      = pos;
        worldPosition = ChunkToWorld(pos);
        worldCenter   = worldPosition + glm::vec2(0.5f * CHUNK_SIZE);
    }

    static constexpr glm::vec2 ChunkToWorld(glm::ivec2 pos)
    {
        return pos * CHUNK_SIZE;
    }

    static constexpr glm::ivec2 WorldToChunk(glm::vec2 pos)
    {
        return glm::ivec2(pos.x / CHUNK_SIZE, pos.y / CHUNK_SIZE);
    }
};
}; // namespace drive
