#include <bits/stdc++.h>

using namespace std;

int BucketSize;

void leakyBucket(int outputRate, int packetSize){
    if(packetSize <= outputRate){
        cout << "Bucket Output is successful " << endl;
        cout << "Last " << packetSize << " bytes was sent" << endl;
    }
    else if(packetSize <= BucketSize){
        cout << "Bucket Output is successful " << endl;
        cout << "Last " << outputRate << " bytes was sent" << endl;
        int rem_size = packetSize - outputRate;
        while(rem_size > 0){
            if(rem_size >= outputRate) cout << "last " << outputRate << " bytes was sent" << endl;

            else cout << "Last " << rem_size << " bytes was sent " << endl;

            rem_size -= outputRate;
        }
    }
    else cout << "Bucket Overflow!" << endl;
}

int main()
{
    cout << "Enter the max bucket size : " ;
    cin >> BucketSize;
    int outputRate;
    cout << "Enter the Output rate : ";
    cin >> outputRate;
    int numberOfPackets;
    cout << "Enter the number of packets : ";
    cin >> numberOfPackets;
    for(int i=0;i<numberOfPackets;i++){
        int packetSize;
        cout << endl;
        cout << "Enter the Packet size : ";
        cin >> packetSize;
        leakyBucket(outputRate, packetSize);
    }
}