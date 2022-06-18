#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this -> size = 0;
        this -> pFirstNode = NULL;

    }

    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
	{
	   returnAux = this -> size;
	}

return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;
    int tam =  ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex < tam)
    {
    	nodo = this->pFirstNode;

    	while(nodeIndex > 0)
		{
    		nodo = nodo->pNextNode;
			nodeIndex --;
		}

    }//fin if

    return nodo;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int tam = ll_len(this);
	Node* node = NULL;
	Node* nodeAnterior = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= tam)
	{
		node = (Node*) malloc(sizeof(Node));
		if(node != NULL)
		{
			node-> pElement = pElement;
		}
		if(nodeIndex == 0)
		{
			node->pNextNode = this->pFirstNode;
			this->pFirstNode = node;
		}
		else
		{
			nodeAnterior = getNode(this, nodeIndex -1);
			node-> pNextNode = nodeAnterior->pNextNode;
			nodeAnterior->pNextNode = node;
		}
		this->size++;
		returnAux = 0;

	}//fin if

return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this, ll_len(this), pElement);
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    Node* auxNode = NULL;

	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		auxNode = getNode(this,index);

		if(auxNode != NULL)
		{
			returnAux = auxNode->pElement;
		}

	}

return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
   int returnAux = -1;
   Node* auxNode = NULL;

   if(this!=NULL && index>=0 && index<ll_len(this))
   {
	   auxNode = getNode(this,index);
	   if(auxNode != NULL)
	   {
		   auxNode->pElement = pElement;
		   returnAux = 0;
	   }
   }

return returnAux;
}


int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* aux = NULL;
	Node* auxPosterior = NULL;
	Node* auxAnterior = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		aux = getNode(this,index);
		if(aux != NULL)
		{
			auxPosterior = aux->pNextNode;
			if(index == 0)
			{
				this->pFirstNode = auxPosterior;
			}else
			{
				auxAnterior = getNode(this,index-1);
				auxAnterior->pNextNode = auxPosterior;
			}
		free(aux);
		this->size--;
		returnAux = 0;
		}
	}

return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int flag = 1;
	if(this!=NULL)
	{
		while(ll_len(this) > 0)
		{
			if(ll_remove(this,0) == -1)
			{
				flag= 0;
				break;
			}
		}

		if(flag)
		{
			returnAux =0;
		}

	}

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
	{
		if(!ll_clear(this))
		{
			free(this);
			returnAux=0;
		}
	}

return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tamanio;

	if(this!=NULL)
	{
		tamanio = ll_len(this);
		for(int i=0;i<tamanio;i++)
		{
			if(ll_get(this,i) == pElement)
			{
				returnAux = i;
				break;
			}

		}//fin for

	}//fin if

return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
	{
		if(ll_len(this))
		{
			returnAux = 0;
		}
		else
		{
			returnAux = 1;
		}
	}
    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >=0 && index <= ll_len(this))
	{
	   if(addNode(this,index,pElement) == 0)
	   {
		  returnAux = 0;
	   }
	}

return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>= 0 && index<ll_len(this))
	{
		returnAux = ll_get(this,index);
		ll_remove(this,index);
	}
    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
	{
		returnAux = 0;
		if(ll_indexOf(this,pElement) != -1)
		{
			returnAux = 1;
		}

	}
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tamThis2;

	if(this != NULL && this2 != NULL)
	{
		tamThis2 = ll_len(this2);
		returnAux = 1;
		for(int i=0;i<tamThis2;i++)
		{
		   if(!ll_contains(this,ll_get(this2,i)))
		   {
				returnAux = 0;
				break;
			}
		}
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL && from >= 0 && from < ll_len(this) && to <= ll_len(this) && to > from)
    {
	   cloneArray = ll_newLinkedList();
	   if(cloneArray != NULL)
	   {
		   for(int i=from;i<to;i++)
		   {
			  ll_add(cloneArray,ll_get(this,i));
		   }
	   }

    }

return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int tamanio;

	if(this != NULL)
	{
		tamanio = ll_len(this);
		cloneArray = ll_subList(this,0,tamanio);
	}

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void*  auxI = NULL;
	void* auxJ = NULL;
	int tam;

	if(this != NULL && pFunc != NULL && order >=0 && order <=1)
	{
		tam = ll_len(this);
		for (int i = 0; i < tam -1; i++)
		{
			for(int j = i + 1; j < tam; j++ )
			{
				auxI = ll_get(this,i);
				auxJ= ll_get(this,j);
				if((pFunc(auxI,auxJ) > 0 && order)
				   || (pFunc(auxI,auxJ) < 0 && !order ))
				{
					 ll_set(this,i, auxJ);
					 ll_set(this,j, auxI);
				}
			}
		}
			returnAux = 0;
	}

return returnAux;
}

LinkedList* ll_filter(LinkedList*  this, int (* pFunc)(void*) )
{
   LinkedList* filterList = NULL;
   void* aux = NULL;
   int tam = 0;

    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();
        if(filterList != NULL)
        {
            tam = ll_len(this);
            for(int i= 0; i <tam ; i++)
            {
                aux = ll_get(this,i);
                if(pFunc(aux))
                {
                   if( ll_add(filterList,aux ))
                   {
                      ll_deleteLinkedList(filterList);
                       filterList = NULL;
                       break;
                   }//fin if

                }//fin fir

            }//fin for

        }//fin if

    }//fin if

return filterList;
}
