all : 1.out

1.out : main.o Gate.o And_gate.o Or_gate.o Not_gate.o Xor_gate.o Nand_gate.o Nor_gate.o wire.o Circuit.o
	g++ main.o Gate.o And_gate.o Or_gate.o Not_gate.o Xor_gate.o Nand_gate.o Nor_gate.o wire.o  Circuit.o -o 1.out

main.o: main.cpp Gate.h And_gate.h Or_gate.h Xor_gate.h Nand_gate.h Nor_gate.h wire.h Circuit.h 
	g++ -c main.cpp -o main.o

Gate.o : Gate.cpp Gate.h 
	g++ -c Gate.cpp -o Gate.o

And_gate.o : And_gate.cpp And_gate.h
	g++ -c And_gate.cpp -o And_gate.o

Or_gate.o : Or_gate.cpp Or_gate.h
	g++ -c Or_gate.cpp -o Or_gate.o

Not_gate.o : Not_gate.cpp Not_gate.h
	g++ -c Not_gate.cpp -o Not_gate.o

Xor_gate.o : Xor_gate.cpp Xor_gate.h
	g++ -c Xor_gate.cpp -o Xor_gate.o

Nand_gate.o : Nand_gate.cpp Nand_gate.h
	g++ -c Nand_gate.cpp -o Nand_gate.o

Nor_gate.o : Nor_gate.cpp Nor_gate.h
	g++ -c Nor_gate.cpp -o Nor_gate.o

wire.o : wire.cpp wire.h 
	g++ -c wire.cpp -o wire.o

Circuit.o : Circuit.cpp Circuit.h Gate.h wire.h
	g++ -c Circuit.cpp -o Circuit.o
# FileSystemInterfaceCopy.o : FileSystemInterfaceCopy.cpp FileSystemInterfaceCopy.h File.h Directory.h Link.h BadElementId.h BadParentId.h BadTitle.h BadLinkedElement.h IdAlreadyExists.h
# 	g++ -c FileSystemInterfaceCopy.cpp -o FileSystemInterfaceCopy.o