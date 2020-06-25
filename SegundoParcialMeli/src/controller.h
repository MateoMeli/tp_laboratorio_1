#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_parserFromText(LinkedList*);
int parser_articulosFromText(FILE* pFile, LinkedList* listaArticulos);
int controller_listArticulos(LinkedList*);
int controller_sortByArticulo(LinkedList*);
int controller_aplicarDescuentos(LinkedList*);
int controller_saveAsText(LinkedList* listaArticulos);
int controllerMenu(LinkedList* listaArticulos);

#endif /* CONTROLLER_H_ */
