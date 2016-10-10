#ifndef __CollisionManager__
#define __CollisionManager__

#include <iostream>
#include <vector>

class Player;
class GameObject;
class TileLayer;

class CollisionManager
{
    public:
    
		// for player attacks
		void checkPlayerEnemyBulletCollision(Player* pPlayer);
	
		// player and enemy collision
		void checkPlayerEnemyCollision(Player* pPlayer, const std::vector<GameObject*> &objects);
	
		// for enemy attacks
		void checkEnemyPlayerBulletCollision(const std::vector<GameObject*>& objects);

		// player with the rest of the world
		void checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*>& collisionLayers);
};

#endif
