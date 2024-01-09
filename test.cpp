#include "pch.h"
#include "CheckMAC.h"
#include "CheckReg.h"
#include "CheckRemote.h"
#include "RDPCheck.h"

TEST(CheckTest, VirtualMachineAndRemoteConnectionDetectCorrectlyWorked) {

	std::string RegKey, MacAddr, Remote;
	bool RDP;

	RegKey = CheckRegKeys();

	//�������� ��� ��� ������� �������� ���������
#ifdef _WIN32
	ASSERT_FALSE(RegKey.empty());
	ASSERT_FALSE(getVMonMAC().empty());
	ASSERT_FALSE(CheckRemote().empty());
#else
	ASSERT_FALSE(getVMonMAC().empty());
	ASSERT_FALSE(CheckRemote().empty());
#endif
	//ASSERT_FALSE(IsRDPConnection() == nullptr);
}

#ifdef _WIN32
//�������� �� ����������� �����
TEST(CheckTest, VMKeyInRegCheck) {
	EXPECT_FALSE(CheckRegKeys() == "host");
}
#endif


TEST(CheckTest, VMMacAddrCheck) {
	EXPECT_FALSE(getVMonMAC() == "host");
}

//�������� �� ��������� �����������
TEST(CheckTest, RemoteProgramCheck) {
	EXPECT_FALSE(CheckRemote() == "host");
}

#ifdef _WIN32
TEST(CheckTest, RDPCheck) {
	EXPECT_TRUE(IsRDPConnection());
}

//�������� �� ���������� ����������� ������
TEST(CheckTest, VMwareRegKeyCheck) {
	EXPECT_TRUE(CheckRegKeys() == "VMware");
}
#endif

TEST(CheckTest, VMwareMACCheck) {
	EXPECT_TRUE(getVMonMAC() == "VMware");
}