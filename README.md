Template I use in my axmol games

Contains:
- A texture pipeline
- A gitinfo pipeline (Writes GITINFO with current branch-commit into Content, optional)
- CMakeLists patch to run the pipeline
- Components
	- InspectorHandler
		```cpp
		addChild(InspectorHandler::create()); // open inspector when transition to the current scene finishes
		```
- Utilities (Source/Utility.h)

Install:
- (Copy over the entire repo without README.md to your game repo)
- ```sh
  patch < CMakeLists.patch # install cmake patch (runs pipeline)
  ```
