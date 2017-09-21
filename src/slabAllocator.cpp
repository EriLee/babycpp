#include "slabAllocator.h"
#include <cassert>

namespace babycpp {
namespace memory {
SlabAllocator::SlabAllocator(int slabSizeInByte) :slabSize(slabSizeInByte)
{
	assert(slabSize != 0);
	//allocating a slab
	Slab& createdSlab = allocateSlab();
	currentSlab = &createdSlab;
}

Slab & SlabAllocator::allocateSlab()
{
	//need to allocate memory
	char* data = new char[slabSize];
	slabs.emplace_back(Slab{data, data,data+slabSize});
	return slabs[slabs.size() - 1];
}
} // namespace memory
} // namespace babycpp