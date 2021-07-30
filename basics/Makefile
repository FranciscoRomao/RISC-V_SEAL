#/usr/bin/c++ -isystem /usr/local/include/SEAL-3.6 -std=gnu++17 -o $@ -c $^

#basics_gcc.o: basicsSEAL.cpp
#	/usr/bin/c++ $^ -I../SEAL_lib_original/ -L../libseal_src/ -c -std=gnu++17 -lseal -o $@

#basics_gcc: basics_gcc.o
#	/usr/bin/c++ $^ -I../SEAL_lib_original/ -L../libseal_src/ -lseal -o $@

basics_gcc: basicsSEAL.cpp
	/usr/bin/c++ $^ -I../libseal_src/ -L../libseal_src/ -lseal -o $@

basics_riscv.o: basicsSEAL.cpp
	@echo "=== Compiling Basics ==="
	/opt/riscv/bin/riscv64-unknown-linux-gnu-g++ $^ -isystem ./SEAL_lib_mod -L../libseal_src/ -lseal -o $@



clean:
	rm *.o basics_gcc basics_riscv

.PHONY: clean
