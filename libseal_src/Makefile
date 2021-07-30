CXX = /usr/bin/c++
#CXX_FLAGS = -std=gnu++17 -shared
CXX_FLAGS = -std=gnu++17 -fPIC
CXX_INCLUDES = -I. -I../SEAL_lib_original/


CC = /usr/bin/cc
C_FLAGS = -fPIC
#C_FLAGS_ZSTD = -fPIC -std=c99
C_FLAGS_ZSTD = -fPIC -std=c99
C_DEFINES_ZSTD = -DXXH_NAMESPACE=ZSTD_ -DZSTD_LEGACY_SUPPORT=0

include zstdlib/depend.make

.DEFAULT: libseal #Não funciona não sei porque usar: make libseal

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
libseal: seal/batchencoder.o
libseal: seal/ciphertext.o
libseal: seal/ckks.o
libseal: seal/context.o
libseal: seal/decryptor.o
libseal: seal/encryptionparams.o
libseal: seal/encryptor.o
libseal: seal/evaluator.o
libseal: seal/keygenerator.o
libseal: seal/kswitchkeys.o
libseal: seal/memorymanager.o
libseal: seal/modulus.o
libseal: seal/plaintext.o
libseal: seal/randomgen.o
libseal: seal/valcheck.o
libseal: seal/util/blake2xb.o
libseal: seal/util/blake2b.o
libseal: seal/util/fips202.o
libseal: seal/util/clipnormal.o
libseal: seal/util/common.o
libseal: seal/util/croots.o
libseal: seal/util/globals.o
libseal: seal/util/galois.o
libseal: seal/serialization.o
libseal: seal/util/hash.o
libseal: seal/util/iterator.o
libseal: seal/util/intel_seal_ext.o
libseal: seal/util/mempool.o
libseal: seal/util/numth.o
libseal: seal/util/polyarithsmallmod.o
libseal: seal/util/rlwe.o
libseal: seal/util/rns.o
libseal: seal/util/scalingvariant.o
libseal: seal/util/ntt.o
libseal: seal/util/streambuf.o
libseal: seal/util/uintarith.o
libseal: seal/util/uintarithmod.o
libseal: seal/util/uintarithsmallmod.o
libseal: seal/util/uintcore.o
libseal: seal/util/ztools.o
	gcc -shared -o libseal.so $^	
	
#ar rcs libseal.a $^

#From libseal
seal/batchencoder.o: seal/batchencoder.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/ciphertext.o: seal/ciphertext.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/ckks.o: seal/ckks.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/context.o: seal/context.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/decryptor.o: seal/decryptor.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/encryptionparams.o: seal/encryptionparams.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/encryptor.o: seal/encryptor.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/evaluator.o: seal/evaluator.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -shared -o $@ -c $^

seal/keygenerator.o: seal/keygenerator.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/kswitchkeys.o: seal/kswitchkeys.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/memorymanager.o: seal/memorymanager.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/modulus.o: seal/modulus.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/plaintext.o: seal/plaintext.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/randomgen.o: seal/randomgen.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/clipnormal.o: seal/util/clipnormal.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/common.o: seal/util/common.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/croots.o: seal/util/croots.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/galois.o: seal/util/galois.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/globals.o: seal/util/globals.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/hash.o: seal/util/hash.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/intel_seal_ext.o: seal/util/intel_seal_ext.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/iterator.o: seal/util/iterator.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/mempool.o: seal/util/mempool.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/ntt.o: seal/util/ntt.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/numth.o: seal/util/numth.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/polyarithsmallmod.o: seal/util/polyarithsmallmod.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/rlwe.o: seal/util/rlwe.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/rns.o: seal/util/rns.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/scalingvariant.o: seal/util/scalingvariant.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/streambuf.o: seal/util/streambuf.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/uintarith.o: seal/util/uintarith.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/uintarithmod.o: seal/util/uintarithmod.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/uintarithsmallmod.o: seal/util/uintarithsmallmod.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/uintcore.o: seal/util/uintcore.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/ztools.o: seal/util/ztools.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/valcheck.o: seal/valcheck.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/serialization.o: seal/serialization.cpp
	$(CXX) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

seal/util/fips202.o: seal/util/fips202.c
	$(CC) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

seal/util/blake2b.o: seal/util/blake2b.c
	$(CC) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

seal/util/blake2xb.o: seal/util/blake2xb.c
	$(CC) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^


#From zlib
zlib/adler32.o: zlib/adler32.c
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/compress.o: zlib/compress.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/crc32.o: zlib/crc32.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/deflate.o: zlib/deflate.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzclose.o: zlib/gzclose.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzlib.o: zlib/gzlib.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzread.o: zlib/gzread.c
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/gzwrite.o: zlib/gzwrite.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/inflate.o: zlib/inflate.c
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/infback.o: zlib/infback.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/inftrees.o: zlib/inftrees.c
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/inffast.o: zlib/inffast.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^

zlib/trees.o: zlib/trees.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^
	
zlib/uncompr.o: zlib/uncompr.c
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^
	
zlib/zutil.o: zlib/zutil.c	
	$(CC) $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o $@ -c $^


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

clean:
	find . -name "*.o" -delete
	find . -name "*.so" -delete