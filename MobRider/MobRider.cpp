#include "pch.h"

void entry()
{
	std::cout << "[MobRider] Loaded!\n";
}

THook(bool, "?attack@Player@@UEAA_NAEAVActor@@@Z", Player* pl, Actor* ac)
{
	if (pl->getCarriedItem().getId() == 270 && ac->getEntityTypeId() == 1)
	{
		auto ac2 = LocateS<WLevel>()->getPlayer(ac->getNameTag());
		auto pl2 = LocateS<WLevel>()->getPlayer(pl->getNameTag());
		if (ac2.value()->getCarriedItem().getId() != 270) {
			pl2.value().sendText(u8"��a[PlayerRider] ֻ�е��Է�Ҳ����ľ��ʱ������Է�", TextType{ TIP });
			return false;
		}
		ac2.value()->addRider(*pl);
		ac2.value().sendText("��c[PlayerRider] ��ΪBUG������Ҫ���Ͽ�����Ķ���Ȼ��Ͽ����������Ӳ���������ȡ������״̬");
		return false;
	}
	return original(pl, ac);
}