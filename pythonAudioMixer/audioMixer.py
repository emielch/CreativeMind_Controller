import os, pygame, sys
from pygame import *
import serial
import threading
from random import randrange

# usbport =  'COM7'
usbport = '/dev/ttyACM0'
serial_port = serial.Serial(usbport, 9600)

bpm = 60  # beats per minute
lastTick = 0

actCurrentSample = 0 # counter for current activity sample
activity = 0
actSampleTime = 1000 # the time in which one activity sample is taken
lastActSampleTime = 0

lastNotePlayed = 0
minNoteDelay = 100


mixer.pre_init(frequency=44100, size=-16, channels=2, buffer=512)
pygame.init()
print pygame.mixer.get_init()
screen=pygame.display.set_mode((400,400),0,32)
mixer.set_num_channels(64)

state = []
noteSound_base = []
noteSound_delay = []
chordSound = []
bass1Sound = []
bass2Sound = []
bass3Sound = []
bass4Sound = []

notePath_base = "./audioSamples_16Bit/note_base"
notePath_delay = "./audioSamples_16Bit/note_delay"
chordPath = "./audioSamples_16Bit/chords"
bass1Path = "./audioSamples_16Bit/bass1"
bass2Path = "./audioSamples_16Bit/bass2"
bass3Path = "./audioSamples_16Bit/bass3"
bass4Path = "./audioSamples_16Bit/bass4"

noteFiles_base = os.listdir(notePath_base)
noteFiles_delay = os.listdir(notePath_delay)
chordFiles = os.listdir(chordPath)

bass1Files = os.listdir(bass1Path)
bass2Files = os.listdir(bass2Path)
bass3Files = os.listdir(bass3Path)
bass4Files = os.listdir(bass4Path)

noteFiles_base.sort()
noteFiles_delay.sort()
chordFiles.sort()

bass1Files.sort()
bass2Files.sort()
bass3Files.sort()
bass4Files.sort()

def active(incr):
    global actCurrentSample, state, currState
    actCurrentSample += incr



class state:

    def __init__(self, notes, coreNotes, chords, bass, bassBeats):
        self.notes = notes
        self.coreNotes = coreNotes
        self.chords = chords
        self.bass = bass
        self.bassBeats = bassBeats

        self.currNote = 0
        self.nextBassTick = 0

    def playNote(self):
        if(self.currNote < len(self.notes)):
            self.notes[self.currNote].set_volume(0.7)
            self.notes[self.currNote].play()

    def playCoreNote(self):
        if(self.currNote < len(self.coreNotes)):
            self.coreNotes[self.currNote].set_volume(0.7)
            self.coreNotes[self.currNote].play()

    def playBass(self):
        bassNote = 	randrange(len(self.bass))
        self.bass[bassNote].set_volume(0.7)
        self.bass[bassNote].play()

    def update(self, preTic, curTick):
        beatLen = (60*1000) / bpm
        loopLenMillis = self.chords.loopLen * beatLen  # the amount of beats, times one beat duration
        preBeat = (preTic % loopLenMillis) / float(beatLen)
        curBeat = (curTick % loopLenMillis) / float(beatLen)
        for chord in self.chords.chordArr:
            if((preBeat <= chord.startbeat or preBeat>curBeat) and curBeat > chord.startbeat):
                chord.play()

        if curTick > self.nextBassTick:
            self.playBass()
            bassBeat = self.bassBeats[ randrange(len(self.bassBeats)) ]
            self.nextBassTick = curTick + bassBeat*beatLen



class chords:
    def __init__(self, loopLen, chordArr):
        self.loopLen = loopLen  # length of the chords loop in beats
        self.chordArr = chordArr


class chord:
    def __init__(self, startbeat, samples):
        self.startbeat = startbeat  # beat at which to start the chord
        self.samples = samples  # array of sound samples, that together form a chord
    def play(self):
        for sample in self.samples:
            sample.set_volume(1)
            sample.play()


def loadSamples(path, files, soundDict):
    for file in files:
        if file.endswith(".wav"):
            soundDict.append( pygame.mixer.Sound(path + "/" + file) ) #load audio sample in the mixer, and put it in list


loadSamples(notePath_base, noteFiles_base, noteSound_base)
loadSamples(notePath_delay, noteFiles_delay, noteSound_delay)
loadSamples(chordPath, chordFiles, chordSound)

loadSamples(bass1Path, bass1Files, bass1Sound)
loadSamples(bass2Path, bass2Files, bass2Sound)
loadSamples(bass3Path, bass3Files, bass3Sound)
loadSamples(bass4Path, bass4Files, bass4Sound)


chords1 = chords( 2.3, [ chord(0,[chordSound[0]]) ])
chords2 = chords( 2.3, [ chord(0,[chordSound[1]]) ])
chords3 = chords( 2.3, [ chord(0,[chordSound[2]]) ])
chords4 = chords( 2.3, [ chord(0,[chordSound[3]]) ])

notes_min = [1,2,3,11,12,13,2,3,5,13,15,16,5,6,7,16,17,19,7,9,11,19,21,19,17,16,9,7,6,5,17,16,15,13,6,5,3,2,15,13,12,11,3,2,1]
notes_maj = [1,2,4,11,12,14,2,4,5,14,15,16,5,6,8,16,18,20,8,10,11,20,21,20,18,16,9,8,6,5,18,16,15,14,6,5,4,2,15,14,12,11,4,2,1]

melody_min_base = []
melody_maj_base = []
melody_min_delay = []
melody_maj_delay = []

for noteNum in notes_min:
    melody_min_base.append( noteSound_base[noteNum-1] )
    melody_min_delay.append( noteSound_delay[noteNum-1] )

for noteNum in notes_maj:
    melody_maj_base.append( noteSound_base[noteNum-1] )
    melody_maj_delay.append( noteSound_delay[noteNum-1] )

state1 = state( melody_min_base, melody_min_delay, chords1, bass1Sound, [1,1.5,2] )
state2 = state( melody_min_base, melody_min_delay, chords2, bass2Sound, [1,1.5,0.75] )
state3 = state( melody_maj_base, melody_maj_delay, chords3, bass3Sound, [1,0.5,0.75] )
state4 = state( melody_maj_base, melody_maj_delay, chords4, bass4Sound, [0.3,0.5,0.75] )


state = [state1,state2,state3,state4]
currState = state1

def neuronEvent(ID):
    global lastNotePlayed, minNoteDelay

    if time.get_ticks() > lastNotePlayed + minNoteDelay:
        if ID < 6:
            currState.playCoreNote()
        else:
            currState.playNote()

        if currState.currNote >= len(currState.notes):
            currState.currNote = 0
        else:
            currState.currNote += 1
        #print ID
        lastNotePlayed = time.get_ticks()

    active(1)


def handle_Serial_data(data):
    global currState
    if len(data) == 1:
        neuronID = data[0] - 1
        neuronEvent(neuronID)



stopThread = False
serialData = []

def read_from_port(ser):
    global stopThread
    global serialData
    while not stopThread:
        data = ser.read()
        data = ord(data)
        if data == 0:
            handle_Serial_data(serialData)
            serialData = []
        else:
            serialData.append(data)

thread = threading.Thread(target=read_from_port, args=(serial_port,))
thread.start()


while True:
    currTick = time.get_ticks()
    currState.update(lastTick,currTick)


    if( currTick > lastActSampleTime + actSampleTime ):
        print "activity: ", activity
        activity = activity * 0.9 + actCurrentSample * 0.1

        actCurrentSample = 0
        lastActSampleTime = currTick



        if(activity > 10):
            if(currState != state[3]):
                currState = state[3]
                print "state4"
        elif(activity > 6):
            if(currState != state[2]):
                currState = state[2]
                print "state3"
        elif(activity > 2):
            if(currState != state[1]):
                currState = state[1]
                print "state2"
        elif(activity > 0):
            if(currState != state[0]):
                currState = state[0]
                print "state1"


    for event in pygame.event.get():
        if event.type == QUIT:
            stopThread = True
            serial_port.close()
            pygame.quit()
            sys.exit()
        if event.type == KEYDOWN:
            if event.key==K_ESCAPE:
                stopThread = True
                serial_port.close()
                pygame.quit()
                sys.exit()
            elif event.key==K_UP:
                True
            elif event.key==K_DOWN:
                True
            elif event.key==K_a:
                currState = state1
            elif event.key==K_s:
                currState = state2
            else:
                try:
                    keyNum = int(event.unicode)
                    neuronEvent(keyNum)
                    active(5)
                except ValueError:
                    print 'Please enter an integer'
    lastTick = currTick
    #pygame.display.update()
    #time.delay(20)
