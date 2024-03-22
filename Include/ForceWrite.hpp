#ifndef FORCEWRITE_HPP
#define FORCEWRITE_HPP

#include <cstdint>

namespace ForceWrite {
	class Writer {
		int fd;

	public:
		Writer();
		Writer(const Writer&) = delete;
		~Writer();

		void write(void* ptr, const void* bytes, std::size_t length) const;

		template <typename T>
		void write(T* ptr, const T& value) const
		{
			write(ptr, reinterpret_cast<const void*>(&value), sizeof(T));
		}
	};

}

#endif
