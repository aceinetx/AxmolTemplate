import fnmatch
import os

from PyTexturePacker import Packer
from repopath import repopath
from pathlib import Path

packer = Packer.create(
    max_width=2048,
    max_height=2048,
    bg_color=0x00000000,
    enable_rotated=True,
    trim_mode=1,
)

sheets = []
for p in Path(f"{repopath}/DevContent").iterdir():
    if p.is_dir():
        sheets.append(p.name)

for sheet in sheets:
    packer.pack(f"{repopath}/DevContent/{sheet}", f"{repopath}/Content/{sheet}")
    print(f"Pipeline: Packed textures, sheet : {sheet}")
