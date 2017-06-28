#include "sha256.h"
extern "C"
{
#include "impl/sha256.h"
}

std::string SHA256Hex(const std::string &str)
{
	uint8 digest[32];
	sha256_context ctx;

	sha256_starts(&ctx);
	sha256_update(&ctx, (uint8*)str.c_str(), str.length());
	sha256_finish(&ctx, digest);

	char buf[100];
	for (int i = 0; i < 32; i++)
		sprintf(buf + i * 2, "%02x", digest[i]);

	return std::string(buf);
}
