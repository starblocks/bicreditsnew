
#include "net.h"
#include "banknodeconfig.h"
#include "util.h"

CBanknodeConfig banknodeConfig;

void CBanknodeConfig::add(std::string alias, std::string ip, std::string privKey, std::string txHash, std::string outputIndex) {
    CBanknodeEntry cme(alias, ip, privKey, txHash, outputIndex);
    entries.push_back(cme);
}

bool CBanknodeConfig::read(std::string& strErr) {
    boost::filesystem::ifstream streamConfig(GetBanknodeConfigFile());
    if (!streamConfig.good()) {
        return true; // No banknode.conf file is OK
    }

    for(std::string line; std::getline(streamConfig, line); )
    {
        if(line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        std::string alias, ip, privKey, txHash, outputIndex;
        if (!(iss >> alias >> ip >> privKey >> txHash >> outputIndex)) {
            strErr = "Could not parse banknode.conf line: " + line;
            streamConfig.close();
            return false;
        }


        add(alias, ip, privKey, txHash, outputIndex);
    }

    streamConfig.close();
    return true;
}
