
#include "GroupManager.h"
#include "ConsoleLight.h"
#include "Milight.h"

#include <string>
#include <vector> 
#include <utility> 
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>



GroupManager::GroupManager ()
{

}

void GroupManager::AddLight(ProgrammableLight* light)
{
	ListeningLights.push_back(light);

}

void GroupManager::SetGroups(const int Group, Command CommandItem)
{

    Colour empty;
    std::pair<std::map<int, Colour>::iterator, bool> ret;

    switch (CommandItem.Operation) {
    case set:
        CurrentlySelectedGroups.clear();
        AddToCurrentGroups(Group);
        break;
    case add:
        AddToCurrentGroups(Group);
        break;
    case Remove:
        std::pair<const int, colour_combiner> *Entry = GetGroupByID(Group);

        CurrentlySelectedGroups.erase(std::remove(CurrentlySelectedGroups.begin(),
                                                  CurrentlySelectedGroups.end(),
                                                  Entry),
                                                  CurrentlySelectedGroups.end());
        
        break;
    }

    for (ProgrammableLight* light : ListeningLights) {
        light->OnCurrentGroupsUpdate(CommandItem, CurrentlySelectedGroups);
    }

    std::cout << "Current Groups are now: ";
    for (const std::pair<const int, colour_combiner>* group : CurrentlySelectedGroups) {
            std::cout << group->first << ", ";
    }
    std::cout << std::endl;

    //Send CUrrently selected groups to each light
}

void GroupManager::AddToCurrentGroups(const int GroupToAdd)
{
    Colour empty;
    std::pair<const int, colour_combiner>* Entry = GetGroupByID(GroupToAdd);
    //A pointer is used to ensure that the group is kept track of
    
    const int *PointerToGroupID = &Entry->first; //Redundant?
    
    CurrentlySelectedGroups.push_back(GetGroupByID(GroupToAdd));
}

std::pair<const int, colour_combiner> *GroupManager::GetGroupByID(const int ID)
{
	colour_combiner empty;
    std::pair<const int, colour_combiner> *Entry;
    //If ID already exists, that one is returned instead
    Entry = &*(AllGroups.insert(std::pair<int, colour_combiner>(ID, empty)).first);
    return Entry;
}



void GroupManager::UpdateColour(const Colour OutputColour, Command item) {
	for (std::pair<const int, colour_combiner> *group : CurrentlySelectedGroups)
	{
		group->second.set_new(OutputColour, item.Operation);
	}

	for (ProgrammableLight* light : ListeningLights) {
		light->EmitColour(item, CurrentlySelectedGroups);
	}
}

void GroupManager::SpecificCommand(const Command command){
    for (ProgrammableLight* light : ListeningLights) {
        light->SpecificCommand(command);
    }
}