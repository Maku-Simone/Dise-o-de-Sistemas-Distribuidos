/* Archivo op.x */

struct NUM{
	float i;
	float j;
};

program OP_PROG {
   version OP_VERS {
     struct NUM SUMA(struct NUM numeros) = 1;
     struct NUM PRODUCTO(struct NUM numeros) = 2;
     struct NUM COCIENTE(struct NUM numeros) = 3;
   } = 1;
} = 0x31111111;
