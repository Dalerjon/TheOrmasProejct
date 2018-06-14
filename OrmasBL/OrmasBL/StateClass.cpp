#include "stdafx.h"
#include "StateClass.h"

namespace BusinessLayer
{
	State::State(DataLayer::stateCollection sCollection)
	{
		id = std::get<0>(sCollection);
		universalID = std::get<1>(sCollection);
		statusID = std::get<2>(sCollection);
		lastChange = std::get<3>(sCollection);
	}

	int State::GetID()
	{
		return id;
	}

	int State::GetUniversalID()
	{
		return universalID;
	}

	int State::GetStatusID()
	{
		return statusID;
	}

	std::string State::GetLastChange()
	{
		return lastChange;
	}

	void State::SetID(int sID)
	{
		id = sID;
	}
	void State::SetUniversalID(int uID)
	{
		universalID = uID;
	}
	void State::SetStatusID(int stsID)
	{
		statusID = stsID;
	}
	void State::SetLastChange(std::string sLastChange)
	{
		lastChange = sLastChange;
	}


	bool State::CreateState(DataLayer::OrmasDal& ormasDal, int uID, int stsID, std::string sLastChange,
		std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, stsID, sLastChange, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		universalID = uID;
		statusID = stsID;
		lastChange = sLastChange;
		if (0 != id && ormasDal.CreateState(id, universalID, statusID, lastChange, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool State::CreateState(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateState(id, universalID, statusID, lastChange, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool State::DeleteState(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteState(id, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}
	bool State::UpdateState(DataLayer::OrmasDal& ormasDal, int uID, int stsID, std::string sLastChange,
		std::string& errorMessage)
	{
		universalID = uID;
		statusID = stsID;
		lastChange = sLastChange;
		if (0 != id && ormasDal.UpdateState(id, universalID, statusID, lastChange, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool State::UpdateState(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateState(id, universalID, statusID, lastChange, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string State::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != universalID || 0 != statusID || !lastChange.empty())
		{
			return ormasDal.GetFilterForState(id, universalID, statusID, lastChange);
		}
		return "";
	}

	bool State::GetStateByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		id = sID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stateCollection> stateVector = ormasDal.GetState(errorMessage, filter);
		if (0 != stateVector.size())
		{
			id = std::get<0>(stateVector.at(0));
			universalID = std::get<1>(stateVector.at(0));
			statusID = std::get<2>(stateVector.at(0));
			lastChange = std::get<3>(stateVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find State with this id";
		}
		return false;
	}

	bool State::GetStateByUniversalID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage)
	{
		universalID = uID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stateCollection> stateVector = ormasDal.GetState(errorMessage, filter);
		if (0 != stateVector.size())
		{
			id = std::get<0>(stateVector.at(0));
			universalID = std::get<1>(stateVector.at(0));
			statusID = std::get<2>(stateVector.at(0));
			lastChange = std::get<3>(stateVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find State with this id";
		}
		return false;
	}

	bool State::IsEmpty()
	{
		if (0 == id && 0 == universalID && 0 == statusID && lastChange == "")
			return true;
		return false;
	}

	void State::Clear()
	{
		id = 0;
		universalID = 0;
		statusID = 0;
		lastChange.clear();
	}

	bool State::IsDuplicate(DataLayer::OrmasDal& ormasDal, int uID, int stsID, std::string sLastChange, std::string& errorMessage)
	{
		State state;
		state.SetUniversalID(uID);
		state.SetStatusID(stsID);
		state.SetLastChange(sLastChange);
		std::string filter = state.GenerateFilter(ormasDal);
		std::vector<DataLayer::stateCollection> stateVector = ormasDal.GetState(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == stateVector.size())
		{
			return false;
		}
		errorMessage = "State with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool State::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		State state;
		state.SetUniversalID(universalID);
		state.SetStatusID(statusID);
		state.SetLastChange(lastChange);
		std::string filter = state.GenerateFilter(ormasDal);
		std::vector<DataLayer::stateCollection> stateVector = ormasDal.GetState(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == stateVector.size())
		{
			return false;
		}
		errorMessage = "State with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}