//
// Created by Max on 28/06/2022.
//

#ifndef HELM_PLUGINPROCESSOR_H
#define HELM_PLUGINPROCESSOR_H

#include "PluginProcessor.h"

//==============================================================================
HelmAudioProcessor::HelmAudioProcessor()
        : AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                                  .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
#endif
                                  .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
#endif
){

}

void HelmAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                       juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    auto numSamples = buffer.getNumSamples();


}

//==============================================================================
void HelmAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

HelmAudioProcessor::~HelmAudioProcessor()
{
}

//==============================================================================
const juce::String HelmAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool HelmAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool HelmAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool HelmAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double HelmAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int HelmAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int HelmAudioProcessor::getCurrentProgram()
{
    return 0;
}

void HelmAudioProcessor::setCurrentProgram (int index)
{
    juce::ignoreUnused (index);
}

const juce::String HelmAudioProcessor::getProgramName (int index)
{
    juce::ignoreUnused (index);
    return {};
}

void HelmAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
    juce::ignoreUnused (index, newName);
}

void HelmAudioProcessor::releaseResources()
{
}

bool HelmAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    if (layouts.getMainInputChannelSet() == juce::AudioChannelSet::disabled()
        || layouts.getMainOutputChannelSet() == juce::AudioChannelSet::disabled())
        return false;

    return true;
}

//==============================================================================
bool HelmAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* HelmAudioProcessor::createEditor()
{
    return nullptr;
}

#endif //HELM_PLUGINPROCESSOR_H
