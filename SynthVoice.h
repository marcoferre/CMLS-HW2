/*
  ==============================================================================

    SynthVoice.h
    Created: 10 May 2020 12:20:06am
    Author:  marco

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include <maximilian.h>

class SynthVoice : public SynthesiserVoice
{
    public: 

        bool canPlaySound(SynthesiserSound* sound)
        {
            return dynamic_cast<SynthSound*>(sound) != nullptr;
        }

        //===========================================

        void getOscType(float* selection)
        {
            theWave = *selection;
        }

        //===========================================

        double setOscType()
        {
            double sample1;

            switch (theWave)
            {
            case 0:
                sample1 = osc1.square(frequency);
                break;
            case 1:
                sample1 = osc1.saw(frequency);
                break;
            case 2:
                sample1 = osc1.sinewave(frequency);
                break;
            default:
                sample1 = osc1.sinewave(frequency);
                break;
            }

            return sample1;

        }

        //===========================================

        void getEnvelopeParams(float* attack, float* release, float* sustain, float* decay)
        {
            env1.setAttack(*attack);
            env1.setRelease(*release);
            env1.setDecay(*decay);
            env1.setSustain(*sustain);
        }

        //===========================================

        double setEnvelope()
        {
            return env1.adsr(setOscType(), env1.trigger);
        }

        //===========================================

        void getFilterParams(float* filterCutoff, float* filterRes)
        {
            cutoff = *filterCutoff;
            resonance = *filterRes;
        }

        //===========================================

        void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWeelPosition)
        {
            env1.trigger = 1;
            level = velocity;
            frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        }

        //===========================================

        void stopNote(float velocity, bool allowTaleOff)
        {
            env1.trigger = 0;
            allowTaleOff = true;

            if (velocity == 0)
                clearCurrentNote();
        }

        //===========================================

        void renderNextBlock(AudioBuffer <float>& outputBuffer, int startSample, int numSamples) override
        {
            for (int sample = 0; sample < numSamples; ++sample)
            {
                for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
                {
                    outputBuffer.addSample(channel, startSample, setEnvelope() * 0.5);
                }
                ++startSample;
            }
        }

        //===========================================

    private:
        double level;
        double frequency;
        int theWave;

        int filterChoice;
        float cutoff;
        float resonance;

        maxiOsc osc1;
        maxiEnv env1;
        maxiFilter filter1;
};