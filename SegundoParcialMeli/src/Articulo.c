#include "Articulo.h"

eArticulo* articulo_new()
{
	return (eArticulo*) malloc (sizeof(eArticulo));
}

eArticulo* articulo_newParametros(int id, char* articulo, float precio, char* medida, int rubroId)
{
	eArticulo* this;
	this = articulo_new();
	if(this != NULL && articulo != NULL && medida != NULL)
	{
		articulo_setId(this, id);
		articulo_setArticulo(this, articulo);
		articulo_setPrecio(this, precio);
		articulo_setMedida(this, medida);
		articulo_setRubroId(this, rubroId);
	}
	return this;
}

int articulo_getId(eArticulo* this, int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int articulo_setId(eArticulo* this, int id)
{
	int retorno = -1;
	static int maximoId = -1;
	if(this != NULL)
	{
		retorno = 0;
		if(id < 0)
		{
			maximoId ++;
			this->id = maximoId;
		}else
		{
			if(id > maximoId)
			{
				maximoId = id;
				this->id = id;
			}
		}
	}

	return retorno;
}

int articulo_getArticulo(eArticulo* this, char* nomArticulo)
{
	int retorno = -1;
	if(this != NULL && nomArticulo != NULL)
	{
		retorno = 0;
		strncpy(nomArticulo, this->articulo, 100);
	}
	return retorno;
}

int articulo_setArticulo(eArticulo* this, char* nomArticulo)
{
	int retorno = -1;
	if(this != NULL && nomArticulo != NULL)
	{
		retorno = 0;
		strncpy(this->articulo, nomArticulo, 100);
	}
	return retorno;
}

int articulo_getPrecio(eArticulo* this, int* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int articulo_setPrecio(eArticulo* this, int precio)
{
	int retorno = -1;
	if (this != NULL && precio >= 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}

int articulo_getMedida(eArticulo* this, char* medida)
{
	int retorno = -1;
	if(this != NULL && medida != NULL)
	{
		retorno = 0;
		strncpy(medida, this->medida, 20);
	}
	return retorno;
}

int articulo_setMedida(eArticulo* this, char* medida)
{
	int retorno = -1;
	if(this != NULL && medida != NULL)
	{
		retorno = 0;
		strncpy(this->medida, medida, 20);
	}
	return retorno;
}

int articulo_getRubroId(eArticulo* this, int* rubroId)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		*rubroId = this->rubroId;
	}
	return retorno;
}

int articulo_setRubroId(eArticulo* this, int rubroId)
{
	int retorno = -1;
	if(this != NULL && rubroId >= 1 && rubroId <= 4)
	{
		this->rubroId = rubroId;
		retorno = 0;
	}
	return retorno;
}

int articulo_sortArticulo(void* p1, void* p2)
{
	int retorno = 0;
	if(p1 != NULL && p2 != NULL)
	{
		eArticulo* e1;
		eArticulo* e2;
		int comparar;
		char art1 [100];
		char art2 [200];
		e1 = p1;
		e2 = p2;
		if(!articulo_getArticulo(e1, art1) && !articulo_getArticulo(e2, art2))
		{
			comparar = strcmp(art1, art2);
			if(comparar < 0)
			{
				retorno = -1;
			}else if(comparar > 0)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

void articulo_descuentos(void* articulo)
{
	if(articulo != NULL)
	{
		int precio;
		int rubro;
		eArticulo* e1 = articulo;
		articulo_getPrecio(articulo, &precio);
		articulo_getRubroId(e1, &rubro);
		if(rubro == 1)
		{
			if(precio >= 120)
			{
				precio = precio * 0.8;
				articulo_setPrecio(articulo, precio);
			}
		}else if(rubro == 2)
		{
			if(precio <= 200)
			{
				precio = precio * 0.9;
				articulo_setPrecio(articulo, precio);
			}
		}
	}
}






