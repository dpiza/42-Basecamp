#!/bin/sh
ip -brief link | cut -c 33- | cut -d' ' -f1 | tail -n +2