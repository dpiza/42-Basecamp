#!/bin/bash
git status --ignored --porcelain --untracked-files | grep '!!' | cut -c 4-