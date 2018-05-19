#include "player.h"

Player::Player()
	: cash(1000) {

}

void Player::adjustCash(double amount) {
	cash += amount;
}
