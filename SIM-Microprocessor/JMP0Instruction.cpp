#include "JMP0Instruction.h"



JMP0Instruction::JMP0Instruction(std::string inst)
{
	ParseOperands(inst);
}

JMP0Instruction::JMP0Instruction()
{
}


JMP0Instruction::~JMP0Instruction()
{
}

void JMP0Instruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	if ((*((typeid(*in1) == typeid(AddressOperand)) ? mem.GetDataAt(dynamic_cast<AddressOperand*> (in1)) : in1->GetData())) == 0) {
		counter.SetData(*(goToAddr->GetData()));
	}
	else
	{
		counter.SetData(*(counter.GetData()) + 1);
	}
}

void JMP0Instruction::ParseOperands(std::string & str)
{
	std::string str1, str2;
	std::istringstream strStream(str);
	strStream >> str1 >> str2;

	in1 = GetAnyOperand(str1);
	goToAddr = GetAddrOperand(str2);
}
