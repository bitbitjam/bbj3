#include "..\main.h"

// suelo infinito
const s16  raster3DBuffer[224][10] = {
	{-44 ,-47 ,-50 ,-54 ,-57 ,-61 ,-64 ,-67 ,-71 ,-74 },
	{-44 ,-47 ,-50 ,-54 ,-57 ,-60 ,-64 ,-67 ,-71 ,-74 },
    {-44 ,-47 ,-50 ,-54 ,-57 ,-60 ,-64 ,-67 ,-70 ,-74 },
    {-44 ,-47 ,-50 ,-54 ,-57 ,-60 ,-64 ,-67 ,-70 ,-74 },
    {-44 ,-47 ,-50 ,-53 ,-57 ,-60 ,-63 ,-67 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-57 ,-60 ,-63 ,-67 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-57 ,-60 ,-63 ,-66 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-60 ,-63 ,-66 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-60 ,-63 ,-66 ,-69 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-60 ,-63 ,-66 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-63 ,-66 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-66 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-63 ,-66 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-60 ,-63 ,-66 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-60 ,-63 ,-66 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-57 ,-60 ,-63 ,-66 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-63 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-63 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-62 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-62 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-57 ,-59 ,-62 ,-65 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-57 ,-59 ,-62 ,-64 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-57 ,-59 ,-62 ,-64 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-62 ,-64 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-61 ,-64 ,-66 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-61 ,-64 ,-66 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-61 ,-64 ,-66 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-56 ,-58 ,-61 ,-63 ,-66 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-56 ,-58 ,-61 ,-63 ,-66 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-56 ,-58 ,-60 ,-63 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-55 ,-58 ,-60 ,-63 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-55 ,-58 ,-60 ,-63 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-55 ,-58 ,-60 ,-62 ,-65 },
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-60 ,-62 ,-64 },
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-60 ,-62 ,-64 },
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },

	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
	{-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },



	
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-59 ,-62 ,-64 },
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-60 ,-62 ,-64 },
    {-44 ,-46 ,-48 ,-50 ,-53 ,-55 ,-57 ,-60 ,-62 ,-64 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-55 ,-58 ,-60 ,-62 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-55 ,-58 ,-60 ,-63 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-55 ,-58 ,-60 ,-63 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-56 ,-58 ,-60 ,-63 ,-65 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-56 ,-58 ,-61 ,-63 ,-66 },
    {-44 ,-46 ,-48 ,-51 ,-53 ,-56 ,-58 ,-61 ,-63 ,-66 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-61 ,-64 ,-66 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-61 ,-64 ,-66 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-61 ,-64 ,-66 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-56 ,-59 ,-62 ,-64 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-57 ,-59 ,-62 ,-64 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-57 ,-59 ,-62 ,-64 ,-67 },
    {-44 ,-46 ,-49 ,-51 ,-54 ,-57 ,-59 ,-62 ,-65 ,-67 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-62 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-62 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-63 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-54 ,-57 ,-60 ,-63 ,-65 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-57 ,-60 ,-63 ,-66 ,-68 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-60 ,-63 ,-66 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-60 ,-63 ,-66 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-63 ,-66 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-69 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-46 ,-49 ,-52 ,-55 ,-58 ,-61 ,-64 ,-67 ,-70 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-70 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-68 ,-71 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-65 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-62 ,-66 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-59 ,-63 ,-66 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-60 ,-63 ,-66 ,-69 ,-72 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-60 ,-63 ,-66 ,-69 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-56 ,-60 ,-63 ,-66 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-57 ,-60 ,-63 ,-66 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-57 ,-60 ,-63 ,-67 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-53 ,-57 ,-60 ,-63 ,-67 ,-70 ,-73 },
    {-44 ,-47 ,-50 ,-54 ,-57 ,-60 ,-64 ,-67 ,-70 ,-74 },
    {-44 ,-47 ,-50 ,-54 ,-57 ,-60 ,-64 ,-67 ,-70 ,-74 },
    {-44 ,-47 ,-50 ,-54 ,-57 ,-60 ,-64 ,-67 ,-71 ,-74 },
    {-44 ,-47 ,-50 ,-54 ,-57 ,-61 ,-64 ,-67 ,-71 ,-74 }
};


//////////////////////////////////////////////////////////////////////////////////////
//
// selecciona el modo de pantalla, normal 0 o rotado 1
//
//////////////////////////////////////////////////////////////////////////////////////
u8 selectMode(){
	
	unsigned int keys = 0;
	
	u8 mode = 0, keypress = 1;
	
	// cambia el color del fondo
	VDP_setReg(7, 0x01);
	
	VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
	
	VDP_drawText("select tv screen mode", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 10, 8, 0);
	VDP_drawText("HORIZONTAL -YOKO-", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 12, 0);
	VDP_drawText("vertical *tate*", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 13, 14, 0);
	
	VDP_setPalette((u16 *)titleFontPal, 0, 16);
	
	while(1){
		
		// lee el pad
        keys = get_pad(0) & SEGA_CTRL_BUTTONS;
		
		// salimos
        if(keys & SEGA_CTRL_START && keypress == 0){

            keypress = 1;

            break;
        }
		else if((keys & SEGA_CTRL_UP && keypress == 0) || (keys & SEGA_CTRL_LEFT && keypress == 0)){

            keypress = 1;
			
			if( mode == 1 ){
				
				VDP_setPalette((u16 *)palette_black, 0, 16);
				VDP_setPalette((u16 *)palette_black, 16, 16);
				VDP_setPalette((u16 *)palette_black, 32, 16);
				VDP_setPalette((u16 *)palette_black, 48, 16);

				// borro los planos
				VDP_clearPlan(APLAN);
				VDP_clearPlan(BPLAN);
	
				VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
	
				VDP_drawText("select tv screen mode", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 10, 8, 0);
				VDP_drawText("HORIZONTAL -YOKO-", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 12, 0);
				VDP_drawText("vertical *tate*", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 13, 14, 0);
				
				VDP_setPalette((u16 *)titleFontPal, 0, 16);
				mode = 0;
			}
        }
		else if((keys & SEGA_CTRL_DOWN && keypress == 0) || (keys & SEGA_CTRL_RIGHT && keypress == 0)){

            keypress = 1;
			
			if( mode == 0 ){
				
				VDP_setPalette((u16 *)palette_black, 0, 16);
				VDP_setPalette((u16 *)palette_black, 16, 16);
				VDP_setPalette((u16 *)palette_black, 32, 16);
				VDP_setPalette((u16 *)palette_black, 48, 16);

				// borro los planos
				VDP_clearPlan(APLAN);
				VDP_clearPlan(BPLAN);
	
				VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
				
				VDP_drawText("select tv screen mode", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 25, 3, 1);
				VDP_drawText("horizontal *yoko*", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0, pos_vram_font), 20, 5, 1);
				VDP_drawText("VERTICAL -TATE-", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0, pos_vram_font), 18, 6, 1);
				
				VDP_setPalette((u16 *)titleFontPal, 0, 16);
				
				mode = 1;
			}
        }
		else if(!(keys & SEGA_CTRL_START) && !(keys & SEGA_CTRL_UP) && !(keys & SEGA_CTRL_DOWN) && !(keys & SEGA_CTRL_LEFT) && !(keys & SEGA_CTRL_RIGHT))
            keypress = 0;
		
		VDP_waitVSync();
	}
	
	return mode;
}


//////////////////////////////////////////////////////////////////////////////////////
//
//  void updateInfiniteScroll( u8 *frame )
//  actualiza el scroll del suelo infinito
//
//////////////////////////////////////////////////////////////////////////////////////
void updateInfiniteScroll( u8 frame ){

    u8 counter, line = 0;

    // scroll del suelo
    for( counter = 0; counter < 223; counter++ ){
		VDP_setHorizontalScroll(BPLAN, line, raster3DBuffer[counter][frame]);
        line++;
    }
}


////////////////////////////////////////////////////////
//
//	disclaimer del juego
//
////////////////////////////////////////////////////////
void disclaimerScreen( u8 mode ){

    // cadenas de texto
	const char *strV[14] = {
		"warning",
		" ",
		"THIS GAME IS a beta)",
		"DOES NOT REPRESENT the",
		"final quality OF IT AND",
		"IT WILL AVAILABLE IN 2017+",
		"IF YOU PAID FOR IT",
		"YOU HAVE BEEN CHEATED AND",
		" YOU ARE hurting THE scene+",
		" ",
		"THIS GAME IS available IN",
		"www+bitbitjam+com",
		"JUST ENJOY THE GAME AND",
		"DO NOT BE A moron+"
	};
	const u8 str_lenV[14] = {7, 1, 20, 22, 24, 26, 18, 25, 27, 1, 25, 17, 23, 18};

	const char *strH[13] = {
		"warning",
		"THIS GAME IS a beta)",
		"DOES NOT REPRESENT the",
		"final quality OF IT AND",
		"IT WILL AVAILABLE IN 2017+",
		"IF YOU PAID FOR IT",
		"YOU HAVE BEEN CHEATED AND",
		" YOU ARE hurting THE scene+",
		" ",
		"THIS GAME IS available IN",
		"www+bitbitjam+com",
		"JUST ENJOY THE GAME AND",
		"DO NOT BE A moron+"
		/*"warning",
		" ",
		"THIS GAME IS free)",
		"REPRODUCTIONS OF THIS GAME FOR",
		"commercial use ARE prohibited+",
		"IF YOU PAID FOR IT",
		"YOU HAVE BEEN CHEATED AND",
		"YOU ARE damaging THE scene+",
		" ",
		"THIS GAME IS available IN",
		"www+1985alternativo+com",
		"JUST ENJOY THE GAME AND",
		"DO NOT BE A moron+"*/
	};
	//const u8 str_lenH[13] = {7, 1, 18, 30, 30, 18, 25, 27, 1, 25, 17, 23, 18};
	const u8 str_lenH[14] = {7, 20, 22, 24, 26, 18, 25, 27, 1, 25, 17, 23, 18};

   // para el dibujado de las letras una a una
    u8 len = 0, strings = 0, letter = 0, pos = 0, time = 0, num_strings = 0;

    // reseteo las capas, los sprites
    VDP_resetSprites();
    VDP_updateSprites();

    //clear_screen();
    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);

    // cambia el color del fondo
    VDP_setReg(7, 0x0E);

    // cargo la paleta inicial
    VDP_setPalette((u16 *)palette_black, 0, 16);
    VDP_setPalette((u16 *)palette_black, 16, 16);
    VDP_setPalette((u16 *)palette_black, 32, 16);
    VDP_setPalette((u16 *)palette_black, 48, 16);

	if( mode ){
		VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
		num_strings = 14;
		len = str_lenV[strings];
	}
	else{
		VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
		num_strings = 13;
		len = str_lenH[strings];
	}
	
	/////////////////////////////////////////////////////////////////////////////////
	// bios
	{VDP_setPalette((u16 *)titleFontPal, 0, 16);
	
	if( mode ){
		VDP_drawText("ROM RAM CHECK", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 29, 7, 1); //+15,+5
		VDP_drawText(version, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 1, 21, 1);
		VDP_drawText("ver+", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 1, 17, 1);

		delay(30);
		
		VDP_drawText("14j ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 25, 5, 1);
		VDP_drawText("18l ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 5, 1);
		VDP_drawText("10c ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 21, 5, 1);
		VDP_drawText(" 5b ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 19, 5, 1);
		VDP_drawText(" 1a ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 17, 5, 1);
		VDP_drawText("z80 ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 15, 5, 1);
		VDP_drawText("68k ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 13, 5, 1);
		VDP_drawText(" ym ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 11, 5, 1);
		
		VDP_drawText("16j ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 25, 16, 1);
		VDP_drawText("20m ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 16, 1);
		VDP_drawText("12s ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 21, 16, 1);
		VDP_drawText(" 6c ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 19, 16, 1);
		VDP_drawText(" 2b ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 17, 16, 1);
		VDP_drawText("sram ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 15, 16, 1);
		VDP_drawText("wram ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 13, 16, 1);
		VDP_drawText("aram ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 11, 16, 1);
	}
	else{
		VDP_drawText("ROM RAM CHECK", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 14, 2, 0);
		VDP_drawText("ver+", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 26, 26, 0);
		VDP_drawText(version, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 30, 26, 0);

		delay(30);
		
		VDP_drawText("14j ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 6, 0);
		VDP_drawText("18l ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, 0);
		VDP_drawText("10c ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 10, 0);
		VDP_drawText(" 5b ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 12, 0);
		VDP_drawText(" 1a ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 14, 0);
		VDP_drawText("z80 ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 16, 0);
		VDP_drawText("68k ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 18, 0);
		VDP_drawText(" ym ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 20, 0);
		
		VDP_drawText("16j ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 6, 0);
		VDP_drawText("20m ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 8, 0);
		VDP_drawText("12s ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 10, 0);
		VDP_drawText(" 6c ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 12, 0);
		VDP_drawText(" 2b ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 23, 14, 0);
		VDP_drawText("sram ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 16, 0);
		VDP_drawText("wram ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 18, 0);
		VDP_drawText("aram ok", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 20, 0);
	}
	
	delay(60);
		
	VDP_loadTileData(monitorTestTiles, 1, 4, 1);
	VDP_fillTileMap( BPLAN, monitorTestMap, 0, 0, 40, 28, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));
	
	VDP_setPalette((u16 *)monitorTestPal, 0, 2);
	
	delay(60);
	
	VDP_clearPlan(BPLAN);
	
	delay(60);}
	
	///////////////////////////////////////////////////////////////////////////////////////////
	// disclaimer
    VDP_setPalette((u16 *)titleFontPal, 0, 16);

    // cadena inicial
	if( mode )
		pos = (28 - len ) / 2;
	else
		pos = (40 - len ) / 2;


    // dibuja el texto
    while( strings < num_strings ){

        // dibuja el texto letra a letra
        time++;
        if( time == 2 ){
			if( mode )
				VDP_setTile(APLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0, pos_vram_font+(int)strV[strings][letter])-32, 32-strings*2, letter+pos);
			else
				VDP_setTile(APLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0, pos_vram_font+(int)strH[strings][letter])-32, letter+pos, 2+strings*2);
            
			letter++;
            time = 0;
        }

		if( mode ){
			if( letter == str_lenV[strings]){
				strings++;
				letter = 0;

				len = str_lenV[strings];
				
				pos = (28 - len ) / 2;
			}
		}
		else{
			if( letter == str_lenH[strings]){
				strings++;
				letter = 0;

				len = str_lenH[strings];
				
				pos = (40 - len ) / 2;
			}
		}

        VDP_waitVSync();
    }

   delay(180);

    VDP_initFading1(0, 15, titleFontPal, palette_black, 45);    // from col, to col, pal src, pal dst, ... , numframes);
    while(VDP_doStepFading1())
        VDP_waitVSync();
}


//////////////////////////////////////////////////////////////////////////////////////
//
// dibuja el logo de 1985
//
//////////////////////////////////////////////////////////////////////////////////////
void draw1985Logo( u8 mode ){

	// reseteo las capas, los sprites
    VDP_resetSprites();
    VDP_updateSprites();

    //clear_screen();
    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);

    // cargo la paleta inicial
    VDP_setPalette((u16 *)palette_black, 0, 16);
    VDP_setPalette((u16 *)palette_black, 16, 16);
    VDP_setPalette((u16 *)palette_black, 32, 16);
    VDP_setPalette((u16 *)palette_black, 48, 16);
	
	VDP_setHorizontalScroll(BPLAN, 0, 0);
    VDP_setHorizontalScroll(APLAN, 0, 0);
	VDP_setVerticalScroll(APLAN, 0, 0);
    VDP_setVerticalScroll(BPLAN, 0, 0);

    // cambia el color del fondo
    VDP_setReg(7, 0x0F);

    // cargo los tiles del logo, dibujo el mapa y hago el fade in
	if( mode ){
		VDP_loadTileData( logo1985vTiles, 1, logo1985TilesSize, 1 );
		VDP_fillTileMap( APLAN, logo1985vMap, 20, 6, 10, 16, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));  // plano, mapa, x, y, ancho, alto, atributos de tile
		VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
		
		VDP_drawText("CODE pocketlucho", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 16, 6, mode);
		VDP_drawText("GFX  manutrigger", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 14, 6, mode);
		VDP_drawText("GFX  pixelartm", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 12, 6, mode);
		VDP_drawText("BGM  davidbonus", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 10, 6, mode);
		
		VDP_initFading2(0, 15, palette_black, logo1985vPal, 16, 31, palette_black, titleFontPal, 30);    // from col, to col, pal src, pal dst, numframes);
		while(VDP_doStepFading2()) VDP_waitVSync();
		VDP_setPalette((u16 *)logo1985vPal, 0, 16);
	}
	else{
		VDP_loadTileData( logo1985hTiles, 1, logo1985TilesSize, 1 );
		VDP_fillTileMap( APLAN, logo1985hMap, 12, 4, 16, 10, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));  // plano, mapa, x, y, ancho, alto, atributos de tile
		VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
		
		VDP_drawText("CODE pocketlucho", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 12, 16, mode);
		VDP_drawText("GFX  manutrigger", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 12, 18, mode);
		VDP_drawText("GFX  pixelartm", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 12, 20, mode);
		VDP_drawText("BGM  davidbonus", APLAN, TILE_ATTR_FULL(PAL1, 1, 0, 0,  pos_vram_font), 12, 22, mode);
		
		VDP_initFading2(0, 15, palette_black, logo1985hPal, 16, 31, palette_black, titleFontPal, 30);    // from col, to col, pal src, pal dst, numframes);
		while(VDP_doStepFading2()) VDP_waitVSync();
		VDP_setPalette((u16 *)logo1985hPal, 0, 16);
	}
	
	SND_loadSong_XGM(1);

    delay(120);	// espera

    // fade out
	if( mode ){
		VDP_initFading2(0, 15, logo1985vPal, palette_black, 16, 31, titleFontPal, palette_black, 30);    // from col, to col, pal src, pal dst, numframes);
		while(VDP_doStepFading2()) VDP_waitVSync();
	}
	else{
		VDP_initFading2(0, 15, logo1985hPal, palette_black, 16, 31, titleFontPal, palette_black, 30);    // from col, to col, pal src, pal dst, numframes);
		while(VDP_doStepFading2()) VDP_waitVSync();
	}
}

////////////////////////////////////////////////////////
//
// void exitIntro() NONBANKED{
// salimos de la intro
//
////////////////////////////////////////////////////////
void exitIntro( u8 screen, u8 mode  ){
	
	if( screen == 1 ){
		if( mode ){
			VDP_initFading3(0, 15, pal_intro_01V, palette_black, 16, 31, pal_intro_01SV,  palette_black, 32, 47, titleFontPal,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading3()){ 
				psgFxFrame();	
				VDP_waitVSync();
			}
		}
		else{
			VDP_initFading3(0, 15, pal_intro_01H, palette_black, 16, 31, pal_intro_01SH,  palette_black, 32, 47, titleFontPal,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading3()){ 
				psgFxFrame();	
				VDP_waitVSync();
			}
		}
	}
	else if( screen == 2 ){
		if( mode ){
			VDP_initFading3(0, 15, pal_intro_02V, palette_black, 16, 31, pal_intro_02SV,  palette_black, 32, 47, titleFontPal,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading3()){
				psgFxFrame();	
				VDP_waitVSync();
			}
		}
		else{
			VDP_initFading3(0, 15, pal_intro_02H, palette_black, 16, 31, pal_intro_02SH,  palette_black, 32, 47, titleFontPal,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading3()){
				psgFxFrame();	
				VDP_waitVSync();
			}
		}
	}
	else if( screen == 3 ){
		if( mode ){
			VDP_initFading3(0, 15, pal_intro_03V, palette_black, 16, 31, pal_intro_02SV,  palette_black, 32, 47, titleFontPal,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading3()){
				psgFxFrame();	
				VDP_waitVSync();
			}
		}
		else{
			VDP_initFading3(0, 15, pal_intro_03H, palette_black, 16, 31, pal_intro_02SH,  palette_black, 32, 47, titleFontPal,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading3()){
				psgFxFrame();	
				VDP_waitVSync();
			}
		}
	}
	
    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);
}


////////////////////////////////////////////////////////
//
// void waitBetweenMessages(u8 time)
// pausa entre mensajes
//
////////////////////////////////////////////////////////
u8 waitBetweenMessages(u8 time){

    u8 i;
    unsigned int keys_pad1 = 0;

    for(i = 0; i < time; i++){

        // lee el pad
        keys_pad1 = get_pad(0) & SEGA_CTRL_BUTTONS;

        if( keys_pad1 & SEGA_CTRL_START )
            return 1;

		psgFxFrame();
        VDP_waitVSync();
    }

    VDP_clearPlan(APLAN);

    return 0;
}


////////////////////////////////////////////////////////
//
// u8 waitBetweenLetters(u8 time)
// pausa entre letras
//
////////////////////////////////////////////////////////
u8 waitBetweenLetters(u8 time){

    u8 i;
    unsigned int keys_pad1 = 0;

    for( i = 0; i < time; i++ ){

        // lee el pad
        keys_pad1 = get_pad(0) & SEGA_CTRL_BUTTONS;

        if( keys_pad1 & SEGA_CTRL_START )
            return 1;

		psgFxFrame();
        VDP_waitVSync();
    }

    return 0;
}


////////////////////////////////////////////////////////
//
// void drawScreenIntro( UBYTE screen ) NONBANKED{
// dibuja la imagen que toque en la intro
//
////////////////////////////////////////////////////////
void drawScreenIntro( u8 screen, u8 mode ){

    if( screen == 1 ){

		if( mode ){
			VDP_loadTileData( tiles_intro_01V, 1, tiles_intro_01_size, 1);
			VDP_fillTileMap( BPLAN, map_intro_01V,  20, 6, 10, 14, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));
			
			VDP_loadTileData( tiles_intro_01AV, tiles_intro_01_size+1, 1, 1);
			VDP_loadTileData( tiles_intro_01BV, tiles_intro_01_size+2, 1, 1);
			VDP_loadTileData( tiles_intro_01CV, tiles_intro_01_size+3, 1, 1);
			VDP_loadTileData( tiles_intro_01DV, tiles_intro_01_size+4, 1, 1);
			VDP_loadTileData( tiles_intro_01EV, tiles_intro_01_size+5, 1, 1);
			
			// ojo izquierdo
			props[0].posx = 202;
			props[0].posy = 105;

			props[0].size = SPRITE_SIZE(1, 1);
			props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
			props[0].link  = 1;
			VDP_setSpriteP(0, &props[0]);
			
			// ojo derecho
			props[1].posx = 202;
			props[1].posy = 111;

			props[1].size = SPRITE_SIZE(1, 1);
			props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 1, 0, tiles_intro_01_size+4);
			props[1].link  = 2;
			VDP_setSpriteP(1, &props[1]);
			
			// boca
			props[2].posx = 196;
			props[2].posy = 107;

			props[2].size = SPRITE_SIZE(1, 1);
			props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+1);
			props[2].link  = 2;
			VDP_setSpriteP(2, &props[2]);
			
			VDP_initFading2(0, 15, palette_black, pal_intro_01V, 16, 31, palette_black, pal_intro_01SV,  30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();
		}
		else{
	
			VDP_loadTileData( tiles_intro_01H, 1, tiles_intro_01_size, 1);
			VDP_fillTileMap( BPLAN, map_intro_01H,  13, 6, 14, 10, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));
				
			VDP_loadTileData( tiles_intro_01AH, tiles_intro_01_size+1, 1, 1);
			VDP_loadTileData( tiles_intro_01BH, tiles_intro_01_size+2, 1, 1);
			VDP_loadTileData( tiles_intro_01CH, tiles_intro_01_size+3, 1, 1);
			VDP_loadTileData( tiles_intro_01DH, tiles_intro_01_size+4, 1, 1);
			VDP_loadTileData( tiles_intro_01EH, tiles_intro_01_size+5, 1, 1);
				
			// ojo izquierdo
			props[0].posx = 161;
			props[0].posy = 78;

			props[0].size = SPRITE_SIZE(1, 1);
			props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
			props[0].link  = 1;
			VDP_setSpriteP(0, &props[0]);
				
			// ojo derecho
			props[1].posx = 167;
			props[1].posy = 78;

			props[1].size = SPRITE_SIZE(1, 1);
			props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+4);
			props[1].link  = 2;
			VDP_setSpriteP(1, &props[1]);
				
			// boca
			props[2].posx = 164;
			props[2].posy = 85;

			props[2].size = SPRITE_SIZE(1, 1);
			props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+1);
			props[2].link  = 2;
			VDP_setSpriteP(2, &props[2]);
				
			VDP_initFading2(0, 15, palette_black, pal_intro_01H, 16, 31, palette_black, pal_intro_01SH,  30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();
		}
    }
	else if( screen == 2 ){
		
		if( mode ){
			VDP_initFading2(0, 15, pal_intro_01V, palette_black, 16, 31, pal_intro_01SV,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();

			VDP_loadTileData( tiles_intro_02V, 1, tiles_intro_02_size, 1);
			VDP_fillTileMap( BPLAN, map_intro_02V,  20, 6, 10, 14, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));
			
			VDP_loadTileData( tiles_intro_02AV, tiles_intro_01_size+1, 1, 1);
			VDP_loadTileData( tiles_intro_02BV, tiles_intro_01_size+2, 1, 1);
			VDP_loadTileData( tiles_intro_02CV, tiles_intro_01_size+3, 1, 1);
			VDP_loadTileData( tiles_intro_02DV, tiles_intro_01_size+4, 1, 1);
			VDP_loadTileData( tiles_intro_02EV, tiles_intro_01_size+5, 1, 1);
			
			// ojo izquierdo
			props[0].posx = 206;
			props[0].posy = 109;

			props[0].size = SPRITE_SIZE(1, 1);
			props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
			props[0].link  = 1;
			VDP_setSpriteP(0, &props[0]);
			
			// ojo derecho
			props[1].posx = 206;
			props[1].posy = 112;

			props[1].size = SPRITE_SIZE(1, 1);
			props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+4);
			props[1].link  = 2;
			VDP_setSpriteP(1, &props[1]);
			
			// boca
			props[2].posx = 194;
			props[2].posy = 110;

			props[2].size = SPRITE_SIZE(1, 1);
			props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+1);
			props[2].link  = 2;
			VDP_setSpriteP(2, &props[2]);
			
			VDP_initFading2(0, 15, palette_black, pal_intro_02V, 16, 31, palette_black, pal_intro_02SV,  30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();
		}
		else{
			VDP_initFading2(0, 15, pal_intro_01H, palette_black, 16, 31, pal_intro_01SH,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();

			VDP_loadTileData( tiles_intro_02H, 1, tiles_intro_02_size, 1);
			VDP_fillTileMap( BPLAN, map_intro_02H,  13, 6, 14, 10, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));
			
			VDP_loadTileData( tiles_intro_02AH, tiles_intro_01_size+1, 1, 1);
			VDP_loadTileData( tiles_intro_02BH, tiles_intro_01_size+2, 1, 1);
			VDP_loadTileData( tiles_intro_02CH, tiles_intro_01_size+3, 1, 1);
			VDP_loadTileData( tiles_intro_02DH, tiles_intro_01_size+4, 1, 1);
			VDP_loadTileData( tiles_intro_02EH, tiles_intro_01_size+5, 1, 1);
			
			// ojo izquierdo
			props[0].posx = 165;
			props[0].posy = 80;

			props[0].size = SPRITE_SIZE(1, 1);
			props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
			props[0].link  = 1;
			VDP_setSpriteP(0, &props[0]);
			
			// ojo derecho
			props[1].posx = 168;
			props[1].posy = 80;

			props[1].size = SPRITE_SIZE(1, 1);
			props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+4);
			props[1].link  = 2;
			VDP_setSpriteP(1, &props[1]);
			
			// boca
			props[2].posx = 167;
			props[2].posy = 86;

			props[2].size = SPRITE_SIZE(1, 1);
			props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+1);
			props[2].link  = 2;
			VDP_setSpriteP(2, &props[2]);
			
			VDP_initFading2(0, 15, palette_black, pal_intro_02H, 16, 31, palette_black, pal_intro_02SH,  30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();
		}
    }
	else if( screen == 3 ){
		
		if( mode ){
			VDP_initFading2(0, 15, pal_intro_02V, palette_black, 16, 31, pal_intro_02SV,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();

			VDP_loadTileData( tiles_intro_03V, 1, tiles_intro_03_size, 1);
			VDP_fillTileMap( BPLAN, map_intro_03V,  20, 6, 10, 14, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));
			
			props[0].posx = 320;
			VDP_setSpriteP(0, &props[0]);
			props[1].posx = 320;
			VDP_setSpriteP(1, &props[1]);
			props[2].posx = 320;
			VDP_setSpriteP(2, &props[2]);
			
			VDP_initFading2(0, 15, palette_black, pal_intro_03V, 16, 31, palette_black, pal_intro_02SV,  30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();
		}
		else{
			VDP_initFading2(0, 15, pal_intro_02H, palette_black, 16, 31, pal_intro_02SH,  palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();

			VDP_loadTileData( tiles_intro_03H, 1, tiles_intro_03_size, 1);
			VDP_fillTileMap( BPLAN, map_intro_03H,  13, 6, 14, 10, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));

			props[0].posx = 320;
			VDP_setSpriteP(0, &props[0]);
			props[1].posx = 320;
			VDP_setSpriteP(1, &props[1]);
			props[2].posx = 320;
			VDP_setSpriteP(2, &props[2]);
			
			VDP_initFading2(0, 15, palette_black, pal_intro_03H, 16, 31, palette_black, pal_intro_02SH,  30);    // from col, to col, pal src, pal dst, ... , numframes);
			while(VDP_doStepFading2()) VDP_waitVSync();
		}
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void introScreen(){
// pantalla de la intro
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
u8 introScreen( u8 mode ){
	
	// cadenas de texto de l intro
    const char *str[num_strings_intro] = {
        "sometime in the future+++ ",

        "welcome to the news+ ",
		
		  "police arrested the ",
		"child of the exorcist ",
		"with cocaine+ ",
		
		"she is accused of possesion+ ",
		
		"breaking news) ",
		"the president is gonna ",
		"make an announcement+ ",
		
		"citizens) the downforce ",
		"tournament has begun+ ",
		
		"the winner wont be the  ",
		"fastest+++ will be who  ",
		"survive the racing+ ",
		
		"the red hot princess ",
		"is blood thirsty+ ",
		
		"please) enjoy the circus) ",
		"and do not think+++ ",
    };
	
	// numero de cadenas por pantalla
    const u8 num_strings[num_screens_intro] = {1, 1, 3, 1, 3, 2, 3, 2, 2};
	const u8 map_screen[num_screens_intro] = {0, 1, 1, 1, 1, 2, 2, 3, 3};
	
	 // cadena temporal que dibujaremos
    char str_temp[32];

    // para el dibujado de las letras una a una
	u8 a, b, c, d, e = 0, f, num_string ;
	u32 len;
	
	// retraso entre letras
    u8 delay = 5;

    // cargo la paleta inicial y reseteo las capas, los sprites
    VDP_setPalette((u16 *)palette_black, 0, 16);
    VDP_setPalette((u16 *)palette_black, 16, 16);
    VDP_setPalette((u16 *)palette_black, 32, 16);
    VDP_setPalette((u16 *)palette_black, 48, 16);
	
	// cambia el color del fondo
    VDP_setReg(7, 0x0F);
	
    VDP_resetSprites();
    VDP_updateSprites();

    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);
	
	VDP_setHorizontalScroll(BPLAN, 0, 0);
    VDP_setHorizontalScroll(APLAN, 0, 0);
    VDP_setVerticalScroll(BPLAN, 0, 0);
	
    for( a = 3; a < 7; a++)
        VDP_setVerticalScroll(APLAN, a, 0);

	// cargo los tiles
	if( mode )
		VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
	else
		VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
	
    VDP_setPalette((u16 *)titleFontPal, 32, 16);
	
    ////////////////////////////////////////////////////////////////////////
    // para cada pantalla de la intro
    num_string = 0;
    for( a = 0; a < num_screens_intro; a++ ){

        // dibujo el fondo de cada pantalla
        if( a!= 0 ){

            if( map_screen[a] != map_screen[a-1])
                drawScreenIntro(map_screen[a], mode);
        }

        // calcula la posicion Y de la frase segun la cantidad de estas por pantalla
		if( mode ){
			if( num_strings[a] == 2 )
				e = 11;
			else if( num_strings[a] == 3 )
				e = 12;
			else if( num_strings[a] == 1 )
				e = 10;
		}
		else{
			if( num_strings[a] == 2 )
				e = 21;
			else if( num_strings[a] == 3 )
				e = 20;
			else if( num_strings[a] == 1 )
				e = 22;
		}

        // dibuja cada frase de la pantalla
        for( b = 0; b < num_strings[a]; b++ ){

            // vemos la longitud de la cadena que toca
			len = strlen_(str[num_string]);
            strncpy( str_temp, str[num_string], len);

            // centra la frase en la pantalla
			if( mode )
				f = ((28-len)>>1)+1;
			else
				f = ((40-len)>>1)+1;

            // dibuja el texto letra a letra
            for(c = 0; c < len; c++){

                // dibuja la letra que toque
				if( mode )
					VDP_setTile(APLAN, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font+(int)str_temp[c])-32, e, f++);
				else
					VDP_setTile(APLAN, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font+(int)str_temp[c])-32, f++, e);
				
				// sonido de las letras si no es espacio
                if( str[num_string][c] != ' '){
					
					//psgFxPlay(psg_select);
                    
                    // animacion boca
                    d = random() % 2;
					
					if( mode ){
						props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+d+2);
						VDP_setSpriteP(2, &props[2]);

						// ojos
						d = random() % 100;
						if( d < 10 ){
							props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+5);
							props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 1, 0, tiles_intro_01_size+5);
							VDP_setSpriteP(0, &props[0]);
							VDP_setSpriteP(1, &props[1]);
						}
						else{
							props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
							props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 1, 0, tiles_intro_01_size+4);
							VDP_setSpriteP(0, &props[0]);
							VDP_setSpriteP(1, &props[1]);
						}
					}
					else{
						props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+d+2);
						VDP_setSpriteP(2, &props[2]);

						// ojos
						d = random() % 100;
						if( d < 10 ){
							props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+5);
							props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+5);
							VDP_setSpriteP(0, &props[0]);
							VDP_setSpriteP(1, &props[1]);
						}
						else{
							props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
							props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+4);
							VDP_setSpriteP(0, &props[0]);
							VDP_setSpriteP(1, &props[1]);
						}
					}
                }
                else{
					if( mode ){
						props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
						props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 1, 0, tiles_intro_01_size+4);
						VDP_setSpriteP(0, &props[0]);
						VDP_setSpriteP(1, &props[1]);
						props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+1);
						VDP_setSpriteP(2, &props[2]);
					}
					else{
						props[0].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+4);
						props[1].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 1, tiles_intro_01_size+4);
						VDP_setSpriteP(0, &props[0]);
						VDP_setSpriteP(1, &props[1]);
						props[2].tile_attr = TILE_ATTR_FULL(PAL1, 1, 0, 0, tiles_intro_01_size+1);
						VDP_setSpriteP(2, &props[2]);
					}
                }
				
                // espera entre letras y si se pulsa START salimos
                if( waitBetweenLetters(delay) ){
                    exitIntro(map_screen[a], mode);
                    return 1;
                }
            }
			
			if( mode )
				e-=2;
			else
				e+=2;

            num_string++;
        }
		
        // pausa entre pantallas
        if( map_screen[a+1] != map_screen[a] ){
            if( waitBetweenMessages(delayBetweenMessages*2) ){
                exitIntro(map_screen[a], mode );
                return 1;
            }
        }
        else{
            if( waitBetweenMessages(delayBetweenMessages) ){
                exitIntro(map_screen[a], mode );
                return 1;
            }
        }
    }

	exitIntro(map_screen[a-1], mode);

    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////
//
//  pantalla de records
//
///////////////////////////////////////////////////////////////////////////////////////
u8 recordsScreen( u8 mode ){

    return 1;
}


//////////////////////////////////////////////////////////////////////////////////////
//
//  pantalla de titulo
//
//////////////////////////////////////////////////////////////////////////////////////
u8 titleScreen( u8 mode, u8 *circuit ){
	
	u8 counter = 0, pstart = 0, posX1, posY1, posX2, posY2, posX3, posY3, keypress = 1, frame = 0;
	unsigned int keys = 0;
	
	// reseteo las capas, los sprites
    VDP_resetSprites();
    VDP_updateSprites();

    //clear_screen();
    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);

    // cargo la paleta inicial
    VDP_setPalette((u16 *)palette_black, 0, 16);
    VDP_setPalette((u16 *)palette_black, 16, 16);
    VDP_setPalette((u16 *)palette_black, 32, 16);
    VDP_setPalette((u16 *)palette_black, 48, 16);
	
	VDP_setHorizontalScroll(BPLAN, 0, 0);
    VDP_setHorizontalScroll(APLAN, 0, 0);
    VDP_setVerticalScroll(BPLAN, 0, 0);

	// posiciones de los textos segun la orientacion de la pantalla y cargo los tiles de la fuente H o V
	if( mode ){
		posX1 = 12; posY1 =	8; posX2 =	3; posY2 = 1; posX3 =	1; posY3 = 1;
		VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
		
		// cargo los tiles del logo y dibuja el mapa
		VDP_loadTileData(logoVTiles, 1+floorTilesSize, logoTilesSize, 1);
		VDP_fillTileMap( APLAN, logoVMap, 20, 3, logoVMapSizeX, logoVMapSizeY, TILE_ATTR_FULL(PAL1, 1, 0, 0, 1+floorTilesSize));
	}
	else{
		posX1 = 13; posY1 =	18; posX2 =	6; posY2 = 24; posX3 =	6; posY3 = 26;
		VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
		
		// cargo los tiles del logo y dibuja el mapa
		VDP_loadTileData(logoHTiles, 1+floorTilesSize, logoTilesSize, 1);
		VDP_fillTileMap( APLAN, logoHMap, 8, 4, logoHMapSizeX, logoHMapSizeY, TILE_ATTR_FULL(PAL1, 1, 0, 0, 1+floorTilesSize));
	}
	
	// dibujo los textos
	VDP_drawText("press  start", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);
	//VDP_drawText("1985 alternativo", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX2, posY2, mode);
	VDP_drawText("not produced under license", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX2, posY2, mode);
    VDP_drawText("from sega enterprises ltd+", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX3, posY3, mode);
	
	// cargo los tiles del fondo y dibuja el mapa
	VDP_loadTileData(floorTiles, 1, floorTilesSize, 1);
	VDP_fillTileMap( BPLAN, floorMap, 0, 0, floorTileXSize, floorTileYSize, TILE_ATTR_FULL(PAL0, 1, 0, 0, 1));

	// estrellas
    VDP_loadTileData(starsTiles, 1+floorTilesSize+logoTilesSize, 3, 1);
	
	// scroll por lineas
    VDP_setReg(11, 0x07);
	
	// cambia el color del fondo
	VDP_setReg(7, 0x3F);
	
	// fade in de paleta
	if( mode ){
		VDP_initFading3(0, 15, palette_black, floorPal, 16, 31, palette_black, logoVPal, 48, 63, palette_black, titleFontPal, 30);    // from col, to col, pal src, pal dst, ... , numframes);
		do{
			frame %= 10;
			frame++;
			
			VDP_waitVSync();
			updateInfiniteScroll( frame );
			
		}
		while(VDP_doStepFading3());
		VDP_setPalette((u16 *)floorPal, 0, 16);
		VDP_setPalette((u16 *)logoVPal, 16, 16);
		VDP_setPalette((u16 *)titleFontPal, 48, 16);
	}
	else{
		VDP_initFading3(0, 15, palette_black, floorPal, 16, 31, palette_black, logoHPal, 48, 63, palette_black, titleFontPal, 30);    // from col, to col, pal src, pal dst, ... , numframes);
		do{
			frame %= 10;
			frame++;
			
			VDP_waitVSync();
			updateInfiniteScroll( frame );
		}
		while(VDP_doStepFading3());
		VDP_setPalette((u16 *)floorPal, 0, 16);
		VDP_setPalette((u16 *)logoHPal, 16, 16);
		VDP_setPalette((u16 *)titleFontPal, 48, 16);
	}
	
	SND_loadSong_XGM(2);
	
	// bucle press start
	while(1){
			
		// lee el pad
        keys = get_pad(0) & SEGA_CTRL_BUTTONS;
		
		// salimos
        if(keys & SEGA_CTRL_START && keypress == 0){

            keypress = 1;

            break;
        }
		else if(!(keys & SEGA_CTRL_START))
            keypress = 0;
		
		// parpadeo del press start
		counter++;
		if( counter == 40 ){

			if ( pstart )
				VDP_drawText("press  start", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);
			else
				VDP_drawText("            ", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);

			pstart = !pstart;
			counter = 0;
		}
		
		frame %= 10;
		frame++;
		updateInfiniteScroll( frame );

		VDP_waitVSync();
	}
	
	VDP_drawText("            ", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);
	
	if( mode ){
		posX1 = 13; posY1 =	9; posX2 =	11; posY2 = 9; 
	}
	else{
		posX1 = 14; posY1 =	17; posX2 =	14; posY2 = 19; 
	}
	
	VDP_drawText("DEATH RACE", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);
	VDP_drawText("time trial", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX2, posY2, mode);
	
	// eleccion de modo
	while(1){
		
		// lee el pad
        keys = get_pad(0) & SEGA_CTRL_BUTTONS;
		
		if(keys & SEGA_CTRL_UP && keypress == 0){
			
			*circuit = 0;
			VDP_drawText("DEATH RACE", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);
			VDP_drawText("time trial", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX2, posY2, mode);
			
			keypress = 1;
		}
		else if(keys & SEGA_CTRL_DOWN && keypress == 0){
			
			*circuit = 1;
			VDP_drawText("death race", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX1, posY1, mode);
			VDP_drawText("TIME TRIAL", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), posX2, posY2, mode);
			
			keypress = 1;
		}
        else if(keys & SEGA_CTRL_START && keypress == 0){

            keypress = 1;

            break;
        }
		else if(!(keys & SEGA_CTRL_START) && !(keys & SEGA_CTRL_UP) && !(keys & SEGA_CTRL_DOWN))
            keypress = 0;
		
		frame %= 10;
		frame++;
		updateInfiniteScroll( frame );

		VDP_waitVSync();
	}
	
	// fade out de paleta
	if( mode ){
		VDP_initFading3(0, 15, floorPal, palette_black, 16, 31, logoVPal, palette_black, 48, 63, titleFontPal, palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
		while(VDP_doStepFading3())
			VDP_waitVSync();
	}
	else{
		VDP_initFading3(0, 15, floorPal, palette_black, 16, 31, logoHPal, palette_black, 48, 63, titleFontPal, palette_black, 30);    // from col, to col, pal src, pal dst, ... , numframes);
		while(VDP_doStepFading3())
			VDP_waitVSync();
	}
	
	SND_stopPlay_XGM();
	
    return 1;
}

