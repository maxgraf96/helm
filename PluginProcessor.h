//
// Created by Max on 28/06/2022.
//
#pragma once

#ifndef HELM_PROCESSOR_H
#define HELM_PROCESSOR_H

#include <juce_audio_processors/juce_audio_processors.h>

using namespace juce;
using namespace std;

//==============================================================================
class HelmAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    HelmAudioProcessor();
    ~HelmAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

private:
    // State management
//    AudioProcessorValueTreeState valueTreeState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelmAudioProcessor)
    //==============================================================================
};
#endif