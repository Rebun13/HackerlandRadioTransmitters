# HackerlandRadioTransmitters

## Description

Hackerland is a one-dimensional city with houses aligned at integral locations along a road. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a fixed range meaning it can transmit a signal to all houses within that number of units distance away.

Given a map of Hackerland and the transmission range, determine the minimum number of transmitters so that every house is within range of at least one transmitter. Each transmitter must be installed on top of an existing house.

## Returns

- int: the minimum number of transmitters to install

## Input Format

- The first line contains two space-separated integers _n_ and _k_, the number of houses in Hackerland and the range of each transmitter.
- The second line contains _n_ space-separated integers describing the respective locations of each house _x[i]_.
