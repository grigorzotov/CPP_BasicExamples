#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

enum PARTITION_LAYOUT { MBR, GPT };
enum DISK_CONTROLLER { IDE, SATA, SCSI };

struct Disk {
	// Data members
	unsigned int     _capacity;
	unsigned int     _usedSpace;

	PARTITION_LAYOUT _partLayout;
	unsigned int     _numPartitions;

	DISK_CONTROLLER  _diskController;

	// Member functions
	void Read() {
		cin >> _capacity >> _usedSpace;

		unsigned int numericVal;
		cin >> numericVal;
		_partLayout = (PARTITION_LAYOUT)numericVal;

		cin >> _numPartitions;

		cin >> numericVal;
		_diskController = (DISK_CONTROLLER)numericVal;
	}

	void Print() {
		cout << "Capacity is: " << _capacity << ", usedSpace is: " << _usedSpace;
		cout << ", the number of partitions is: " << _numPartitions;

		if (MBR == _partLayout) {
			cout << " MBR " << endl;
		}
		else if (GPT == _partLayout) {
			cout << " GPT " << endl;
		}
		else {
			cout << " Unknown partition layout " << endl;
		}

		if (IDE == _diskController) {
			cout << " IDE " << endl;
		}
		else if (SATA == _diskController) {
			cout << " SATA " << endl;
		}
		else if (SCSI == _diskController) {
			cout << " SCSI " << endl;
		}
		else {
			cout << " Unknown disk controller " << endl;
		}
	}
};

bool
compareDisks(const Disk& firDisk, const Disk& secDisk)
{
	return (firDisk._diskController == secDisk._diskController &&
		firDisk._partLayout == secDisk._partLayout);
}