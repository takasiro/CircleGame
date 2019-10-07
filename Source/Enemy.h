#pragma once
#include "Constant.h"
#include"Unit.h"
#include "Fairy.h"

class Enemy :public Unit {

private:
	vector<Fairy*> mEquipSlot;//�����g

public:
	Enemy();
	Enemy(int _x, int _y);
	Enemy(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Enemy();

	Unit* GetEnemy() { GetUnit(); }
	int Initialize();//����������
	int Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	int Move(int, int);//�ړ�����
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�


	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X
	
	//����������֐�
	//���� ����������Fairy�^�A����������ꏊ
	int SetFairy(Fairy* _fairy,int _num) {
		mEquipSlot[_num] = _fairy;
		if (mEquipSlot[_num] == _fairy)return 0;
		else return 1;
	}


};