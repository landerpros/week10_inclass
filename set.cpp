#include <iostream>
using namespace std;

// Dinh nghia
struct soHang {
    int heSo;
	int soMu;
	soHang* next;
};

// Them so hang - Tao danh sach ban dau
void addsoHang(soHang*& head, int heSo, int soMu) {
    soHang* newsoHang = new soHang;
    newsoHang->heSo = heSo;
    newsoHang->soMu = soMu;
    newsoHang->next = nullptr;

    if (head == nullptr) {
        head = newsoHang;
    } else {
        soHang* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newsoHang;
    }
}

// Sap xep
void sortsoHang(soHang*& head) {
    soHang* current = head;
    soHang* index = nullptr;

    if (current == nullptr) {
        return;
    } else {
        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->soMu < index->soMu) {
                    swap(current->soMu, index->soMu);
                    swap(current->heSo, index->heSo);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// In bieu thuc
void printsoHang(soHang* head) {
    soHang* current = head;

    if (current == nullptr) {
        cout << "Empty" << endl;
    }
	else {
        cout << "In bieu thuc:" << endl;
        while (current != nullptr) {
            cout << current->heSo <<"x^"<< current->soMu <<" + ";
            current = current->next;
        }
    }
	cout <<endl;
}

// Them so hang vao bieu thuc da co
void addsoHangPromax(soHang*& head, int heSo, int soMu) {
    soHang* newsoHang = new soHang;
    newsoHang->heSo = heSo;
    newsoHang->soMu = soMu;
    newsoHang->next = nullptr;

    if (head == nullptr || head->soMu > soMu) {
        newsoHang->next = head;
        head = newsoHang;
    } else {
        soHang* current = head;
        while (current->next!= nullptr && current->next->soMu < soMu) {
            current = current->next;
        }
        newsoHang->next = current->next;
        current->next = newsoHang;
    }
}

// Cong da thuc
void congsoHang(soHang*& head1, soHang*& head2, soHang*& headMain){
	soHang *current1 = head1;
	soHang *current2 = head2;
	int dem1=0;
	int dem2=0;
	while (current1 != nullptr) {
		dem1++;
		current1->next;
	}
	while (current2 != nullptr) {
		dem2++;
		current2->next;
	}
	if (dem1<dem2) {
		current1=head2;
		current2=head1;
	}
	while ((current1 != nullptr)) {
		if ((current1->soMu == current2->soMu)and(current2 != nullptr)) {
			addsoHang(headMain, (current1->heSo) + (current2->heSo), current1->soMu);
			current1->next;
			current2->next;
		}
		else if (((current1->soMu) > (current2->soMu))and(current2 != nullptr)) {
			addsoHang(headMain, (current1->heSo), (current2->heSo));
			current1->next;
		}
		else if (((current1->soMu) < (current2->soMu))and(current2 != nullptr)) {
			addsoHang(headMain, (current2->heSo), (current2->soMu));
			current2->next;
		}
		else {
			while (current1 != nullptr) {
				addsoHang(headMain, (current1->heSo), (current1->soMu));
				current1->next;
			}
		}
	}
}
// In danh sach cung so mu
void printSamesoMu(soHang*& head, const int& search ) {
    soHang *current = head;
    bool found = false;
    cout << "In danh sach cung so mu" << endl;
    while (current != nullptr) {
        if (current->soMu == search) {
            cout << "He so: " << current->heSo << ", So mu: " << current->soMu << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Empty" << endl;
    }
}

int main() {
    soHang* head1 = nullptr;
	soHang* head2 = nullptr;
	soHang* headMain = nullptr;

    // Add so hang fx
    addsoHang(head1, 1, 2);
    addsoHang(head1, 7, 9);
    addsoHang(head1, 6, 8);

	// Add so hang gx
	addsoHang(head2, 3, 5);
	addsoHang(head2, 2, 9);

    // Sort so hang
    sortsoHang(head1);
	sortsoHang(head2);
	
	// Cong
	congsoHang(head1, head2, headMain);
	
    // Print bieu thuc
    printsoHang(head1);
	printsoHang(head2);
	printsoHang(headMain);
    
    return 0;
}

