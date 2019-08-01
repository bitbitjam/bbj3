#include <genesis.h>
#include "vram.h"



struct vram
{
	u16 pos;
	u16 tiles;
	struct vram *next;
};


static struct vram *_list  = NULL;
static u16          _base  = 0;
static u16          _count = 0;



//////////////////////////////////////////////////////////////////////////////////////////////////////



void vram_init ( u16 base )
{
	_list  = NULL;
	_base  = base;
	_count = 0;
}



void vram_destroy ( )
{
	while ( _list )
	{
		struct vram *aux = _list->next;

		MEM_free ( _list );
		_list = aux;
	}

	_list  = NULL;
	_base  = 0;
	_count = 0;
}





u16 vram_new ( u16 tiles )
{
	u16          pos  = _base;
	struct vram *node = _list;
	struct vram *new  = MEM_alloc ( sizeof ( struct vram ) );
	struct vram *next = NULL;

	if ( !node )
	{
		_list = new;
	}

	while ( node )
	{
		pos  = node->pos + node->tiles;
		next = node->next;

		if ( next == NULL || next->pos >= pos + tiles )
		{
			break;
		}

		node = next;
	}

	new->pos   = pos;
	new->tiles = tiles;
	new->next  = next;

	node->next = new;

	++_count;


	return pos;
}



void vram_delete ( u16 pos )
{
	struct vram *node = _list;
	struct vram *prev = NULL;

	while ( node )
	{
		if ( node->pos == pos )
		{
			prev->next = node->next;
			MEM_free ( node );

			--_count;

			if ( _count == 0 )
			{
				_list = NULL;
			}

			return;
		}

		prev = node;
		node = node->next;
	}
}



u16 vram_count ( )
{
	return _count;
}



/*
void vram_sample ( void )
{
	vram_init(0);
	vram_new(7);
	u16 x = vram_new(13);
	vram_new(927);
	vram_delete ( x );
	vram_new(2);
	u16 y = vram_new(5);
	vram_new(1);
	vram_new(8);
	vram_delete ( y );
	vram_new(3);
	vram_new(2);
	vram_new(1);
	vram_new(3);


	vram_info();
}



void vram_info ()
{
	struct vram *aux = _list;


	u8 i = 3;
	u8 str[10];

	VDP_drawText ( " Nb   Pos   Tiles ", 1, 0 );
	VDP_drawText ( "---- ----- -------", 1, 1 );

	while ( aux )
	{
		uintToStr(i-2, str, 1);
		VDP_drawText(str, 2, i);

		uintToStr(aux->pos, str, 1);
		VDP_drawText(str, 7, i);

		uintToStr(aux->tiles, str, 1);
		VDP_drawText(str, 13, i);

		aux = aux->next;
		i++;
	}
}
*/
