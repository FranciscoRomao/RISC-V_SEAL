CXX = /usr/bin/c++
CXX_INCLUDES = -I/home/romano/IST/Tese/SEAL/native/src -I/home/romano/IST/Tese/SEAL/build/native/src -I/home/romano/IST/Tese/SEAL/thirdparty/msgsl-src/include -I/home/romano/IST/Tese/SEAL/thirdparty/zlib-src -I/home/romano/IST/Tese/SEAL/build/thirdparty/zlib-src -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/lib -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/lib/common
CXX_FLAGS = -O3 -DNDEBUG -fPIC -pthread -std=gnu++17

CC = /usr/bin/cc
C_INCLUDES = -I/home/romano/IST/Tese/SEAL/native/src -I/home/romano/IST/Tese/SEAL/build/native/src -I/home/romano/IST/Tese/SEAL/thirdparty/msgsl-src/include -I/home/romano/IST/Tese/SEAL/thirdparty/zlib-src -I/home/romano/IST/Tese/SEAL/build/thirdparty/zlib-src -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/lib -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/lib/common 
C_FLAGS = -O3 -DNDEBUG -fPIC -pthread

C_FLAGS_ZSTD =  -std=c99 -Wall -Wextra -Wundef -Wshadow -Wcast-align -Wcast-qual -Wstrict-prototypes -O3 -DNDEBUG -fPIC  

C_DEFINES_ZSTD = -DXXH_NAMESPACE=ZSTD_ -DZSTD_LEGACY_SUPPORT=0

C_INCLUDES_ZSTD = -I/home/romano/IST/Tese/SEAL/build/thirdparty/zstd-src/build/cmake/lib -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/build/cmake/lib -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/build/cmake/../../lib -I/home/romano/IST/Tese/SEAL/thirdparty/zstd-src/build/cmake/../../lib/common

include zstdlib/depend.make

#From libseal
batchencoder.o: batchencoder.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

ciphertext.o: ciphertext.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

ckks.o: ckks.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

context.o: context.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

decryptor.o: decryptor.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

encryptionparams.o: encryptionparams.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

encryptor.o: encryptor.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

evaluator.o: evaluator.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

keygenerator.o: keygenerator.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

kswitchkeys.o: kswitchkeys.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

memorymanager.o: memorymanager.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

modulus.o: modulus.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

plaintext.o: plaintext.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

randomgen.o: randomgen.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/clipnormal.o: util/clipnormal.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/common.o: util/common.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/croots.o: util/croots.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/galois.o: util/galois.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/globals.o: util/globals.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/hash.o: util/hash.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/intel_seal_ext.o: util/intel_seal_ext.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/iterator.o: util/iterator.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/mempool.o: util/mempool.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/ntt.o: util/ntt.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/numth.o: util/numth.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/polyarithsmallmod.o: util/polyarithsmallmod.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/rlwe.o: util/rlwe.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/rns.o: util/rns.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/scalingvariant.o: util/scalingvariant.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/streambuf.o: util/streambuf.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/uintarith.o: util/uintarith.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/uintarithmod.o: util/uintarithmod.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/uintarithsmallmod.o: util/uintarithsmallmod.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/uintcore.o: util/uintcore.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/ztools.o: util/ztools.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

valcheck.o: valcheck.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

serialization.o: serialization.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

util/fips202.o: util/fips202.c
	$(CC) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

util/blake2b.o: util/blake2b.c
	$(CC) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

util/blake2xb.o: util/blake2xb.c
	$(CC) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^


#From zlib
zlib/adler32.o: zlib/adler32.c
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/compress.o: zlib/compress.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/crc32.o: zlib/crc32.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/deflate.o: zlib/deflate.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzclose.o: zlib/gzclose.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzlib.o: zlib/gzlib.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzread.o: zlib/gzread.c
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzwrite.o: zlib/gzwrite.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/inflate.o: zlib/inflate.c
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/infback.o: zlib/infback.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/inftrees.o: zlib/inftrees.c
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/inffast.o: zlib/inffast.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/trees.o: zlib/trees.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^
	
zlib/uncompr.o: zlib/uncompr.c
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^
	
zlib/zutil.o: zlib/zutil.c	
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^


#From zstdlib
zstdlib/common/debug.o: zstdlib/common/debug.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/common/entropy_common.o: zstdlib/common/entropy_common.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/common/error_private.o: zstdlib/common/error_private.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/common/fse_decompress.o: zstdlib/common/fse_decompress.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/common/pool.o: zstdlib/common/pool.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/common/threading.o: zstdlib/common/threading.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/common/xxhash.o: zstdlib/common/xxhash.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/common/zstd_common.o: zstdlib/common/zstd_common.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/compress/fse_compress.o: zstdlib/compress/fse_compress.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/hist.o: zstdlib/compress/hist.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/huf_compress.o: zstdlib/compress/huf_compress.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/compress/zstd_compress.o: zstdlib/compress/zstd_compress.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_compress_literals.o: zstdlib/compress/zstd_compress_literals.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_compress_sequences.o: zstdlib/compress/zstd_compress_sequences.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_compress_superblock.o: zstdlib/compress/zstd_compress_superblock.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^
	
zstdlib/compress/zstd_double_fast.o: zstdlib/compress/zstd_double_fast.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_fast.o: zstdlib/compress/zstd_fast.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_lazy.o: zstdlib/compress/zstd_lazy.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_ldm.o: zstdlib/compress/zstd_ldm.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstd_opt.o: zstdlib/compress/zstd_opt.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/compress/zstdmt_compress.o: zstdlib/compress/zstdmt_compress.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/decompress/huf_decompress.o: zstdlib/decompress/huf_decompress.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/decompress/zstd_ddict.o: zstdlib/decompress/zstd_ddict.c
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^	

zstdlib/decompress/zstd_decompress.o: zstdlib/decompress/zstd_decompress.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/decompress/zstd_decompress_block.o: zstdlib/decompress/zstd_decompress_block.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/dictBuilder/cover.o: zstdlib/dictBuilder/cover.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/dictBuilder/divsufsort.o: zstdlib/dictBuilder/divsufsort.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/dictBuilder/fastcover.o: zstdlib/dictBuilder/fastcover.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/dictBuilder/zdict.o: zstdlib/dictBuilder/zdict.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/deprecated/zbuff_common.o: zstdlib/deprecated/zbuff_common.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/deprecated/zbuff_compress.o: zstdlib/deprecated/zbuff_compress.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^

zstdlib/deprecated/zbuff_decompress.o: zstdlib/deprecated/zbuff_decompress.c	
	$(CC) $(C_DEFINES_ZSTD) $(C_INCLUDES_ZSTD) $(C_FLAGS_ZSTD) -o $@ -c $^


#From zstd
libseal: zstdlib/common/debug.o
libseal: zstdlib/common/entropy_common.o
libseal: zstdlib/common/error_private.o
libseal: zstdlib/common/fse_decompress.o
libseal: zstdlib/common/pool.o
libseal: zstdlib/common/threading.o
libseal: zstdlib/common/xxhash.o
libseal: zstdlib/common/zstd_common.o
libseal: zstdlib/compress/fse_compress.o
libseal: zstdlib/compress/hist.o
libseal: zstdlib/compress/huf_compress.o
libseal: zstdlib/compress/zstd_compress.o
libseal: zstdlib/compress/zstd_compress_literals.o
libseal: zstdlib/compress/zstd_compress_sequences.o
libseal: zstdlib/compress/zstd_compress_superblock.o
libseal: zstdlib/compress/zstd_double_fast.o
libseal: zstdlib/compress/zstd_fast.o
libseal: zstdlib/compress/zstd_lazy.o
libseal: zstdlib/compress/zstd_ldm.o
libseal: zstdlib/compress/zstd_opt.o
libseal: zstdlib/compress/zstdmt_compress.o
libseal: zstdlib/decompress/huf_decompress.o
libseal: zstdlib/decompress/zstd_ddict.o
libseal: zstdlib/decompress/zstd_decompress.o
libseal: zstdlib/decompress/zstd_decompress_block.o
libseal: zstdlib/dictBuilder/cover.o
libseal: zstdlib/dictBuilder/divsufsort.o
libseal: zstdlib/dictBuilder/fastcover.o
libseal: zstdlib/dictBuilder/zdict.o
libseal: zstdlib/deprecated/zbuff_common.o
libseal: zstdlib/deprecated/zbuff_compress.o
libseal: zstdlib/deprecated/zbuff_decompress.o

#From zlib
libseal: zlib/adler32.o
libseal: zlib/compress.o	
libseal: zlib/crc32.o	
libseal: zlib/deflate.o	
libseal: zlib/gzclose.o	
libseal: zlib/gzlib.o	
libseal: zlib/gzread.o
libseal: zlib/gzwrite.o	
libseal: zlib/inflate.o
libseal: zlib/infback.o	
libseal: zlib/inftrees.o
libseal: zlib/inffast.o	
libseal: zlib/trees.o	
libseal: zlib/uncompr.o
libseal: zlib/zutil.o

#From seal
libseal: util/blake2b.o
libseal: util/blake2xb.o
libseal: util/fips202.o
libseal: batchencoder.o
libseal: ciphertext.o
libseal: ckks.o
libseal: context.o
libseal: decryptor.o
libseal: encryptionparams.o
libseal: encryptor.o
libseal: evaluator.o
libseal: keygenerator.o
libseal: kswitchkeys.o
libseal: memorymanager.o
libseal: modulus.o
libseal: plaintext.o
libseal: randomgen.o
libseal: serialization.o
libseal: valcheck.o
libseal: util/clipnormal.o
libseal: util/common.o
libseal: util/croots.o
libseal: util/globals.o
libseal: util/galois.o
libseal: util/hash.o
libseal: util/iterator.o
libseal: util/intel_seal_ext.o
libseal: util/mempool.o
libseal: util/numth.o
libseal: util/polyarithsmallmod.o
libseal: util/rlwe.o
libseal: util/rns.o
libseal: util/scalingvariant.o
libseal: util/ntt.o
libseal: util/streambuf.o
libseal: util/uintarith.o
libseal: util/uintarithmod.o
libseal: util/uintarithsmallmod.o
libseal: util/uintcore.o
libseal: util/ztools.o
	ar rcs libseal.a $^

clean:
	rm *.o util\*.o