#include "wavassembler.h"

QQueue<char *> queue;
int underSeven=0;

WavAssembler::WavAssembler() {

}

void WavAssembler::run() {
    assemble();
}

void WavAssembler::receiveBuffer(char *buffer, int bufLen) {
    switch (underSeven) {
    case 0:
        fmtData.cbSize=static_cast<WORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    case 1:
        fmtData.nAvgBytesPerSec=static_cast<DWORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    case 2:
        fmtData.nBlockAlign=static_cast<WORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    case 3:
        fmtData.nChannels=static_cast<WORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    case 4:
        fmtData.nSamplesPerSec=static_cast<DWORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    case 5:
        fmtData.wBitsPerSample=static_cast<WORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    case 6:
        fmtData.wFormatTag=static_cast<WORD>(QString(buffer).left(bufLen).toInt());
        underSeven++;
        break;
    default:
        queue.enqueue(buffer);
        qDebug() << "Length of queue:" << queue.length();
        if (!isRunning()) start();
        break;
    }
    // :'(
}

void WavAssembler::assemble() {
    qDebug() << fmtData.cbSize;
    qDebug() << fmtData.nAvgBytesPerSec;
    qDebug() << fmtData.nBlockAlign;
    qDebug() << fmtData.nChannels;
    qDebug() << fmtData.nSamplesPerSec;
    qDebug() << fmtData.wBitsPerSample;
    qDebug() << fmtData.wFormatTag;


    //    USES_CONVERSION;
    CONST int BUFFER_QUANTITY = 5;
//    WAVEFORMATEX fmtData;
    databuffer.reserve(BUFFER_QUANTITY);
    for (int i=0;i<BUFFER_QUANTITY; i++) {
        WAVEHDR tmp;
        databuffer.push_back(tmp);
    }
    /*--------------------------------------------------------------------------------
        *waveOutOpen(LPHWAVEOUT phwo, UINT uDeviceID, LPWAVEFORMATEX pwfx,
        DWORD dwCallback, DWORD Instance, DWORD fdwOpen);
        *Create a wave device.
        ---------------------------------------------------------------------------------*/
    err = waveOutOpen(&hAudioOut, WAVE_MAPPER, (WAVEFORMATEX *)&fmtData,
                      (DWORD)NULL, 0, CALLBACK_FUNCTION);
    GetWaveError(err);

    /*--------------------------------------------------------------------------------
        *Determine the size of buffer
        ---------------------------------------------------------------------------------*/
    bufferSize = 176400;
    /*--------------------------------------------------------------------------------
        *waveOutPrepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
        *Prepare buffer
        ---------------------------------------------------------------------------------*/
    for (int i = 0; i < BUFFER_QUANTITY; i++) {
        databuffer[i].lpData = (char *) malloc(bufferSize);
        databuffer[i].dwBufferLength = bufferSize;
        databuffer[i].dwFlags = 0;
        databuffer[i].dwLoops = 0;
        memset(databuffer[i].lpData, 0, bufferSize);
        err = waveOutPrepareHeader(hAudioOut, &databuffer[i], sizeof(WAVEHDR));
    }
    /*--------------------------------------------------------------------------------
        *waveOutWrite (HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh );
        *Playback buffer data
        *loop
        ---------------------------------------------------------------------------------*/
    bufferLoop = 0;
    while (1) {
//        if (!queue.isEmpty()) {
//            databuffer[bufferLoop].lpData=queue.dequeue();
//        } else {
//            continue;
//        }
//        mut.lock();
//        waveOutWrite(hAudioOut, &databuffer[bufferLoop], sizeof(WAVEHDR));
//        Sleep(1000); //Please let the second finish first.
//        mut.unlock();
//        waveOutUnprepareHeader(hAudioOut, &databuffer[bufferLoop], sizeof(databuffer[bufferLoop]));
//        memset(databuffer[bufferLoop].lpData, 0, bufferSize);
//        err = waveOutPrepareHeader(hAudioOut, &databuffer[bufferLoop], sizeof(WAVEHDR));
//        bufferLoop++;
//        if (bufferLoop == BUFFER_QUANTITY) {
//            bufferLoop = 0;
//        }
    }
    /*--------------------------------------------------------------------------------
        *mmioClose(HMMIO h, UINT wflags);
        *Close Wav file
        ---------------------------------------------------------------------------------*/



    /*--------------------------------------------------------------------------------
        *mmioClose(HMMIO h, UINT wflags);
        *Close Wav file
        ---------------------------------------------------------------------------------*/
    mmioClose(hmmioIn, 0);

    /*--------------------------------------------------------------------------------
        *waveOutClose(HWAVEOUT hwo);
        *Close audio device
        ---------------------------------------------------------------------------------*/
    waveOutClose(hAudioOut);

    qDebug() << "cat";

    return;

}
