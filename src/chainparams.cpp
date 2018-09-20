// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc1;
        pchMessageStart[1] = 0xa6;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0x71;
        vAlertPubKey = ParseHex("04cdd273904fee60d22ac8b52ebbb77e82b9acb37a134c83531987f3f0ee4291d0047ae55edeb0981d57e0200aba8297bf343384db4ed2cbaff1981921109ed8e0");
        nDefaultPort = 22063;
        nRPCPort = 22073;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "Kavanaugh Accuser Opens Negotiations on Testimony Next Week NY Times 2018-09-20";
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;
        vin.resize(1);
        vout.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        vout[0].nValue = 0;
        vout[0].scriptPubKey = CScript() << ParseHex("04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724") << OP_CHECKSIG;
        CTransaction txNew(1, 1520529257, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1537472018;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 527085;

        hashGenesisBlock = genesis.GetHash();

        /*
        if (true  && (genesis.GetHash() != hashGenesisBlock)) {
		// This will figure out a valid hash and Nonce if you're
		// creating a different genesis block:
			uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
			while (genesis.GetHash() > hashTarget)
			   {
				   ++genesis.nNonce;
				   if (genesis.nNonce == 0)
				   {
					   LogPrintf("NONCE WRAPPED, incrementing time");
					   ++genesis.nTime;
				   }
			   }

        }

        LogPrintf("block.GetHash() == %s\n", genesis.GetHash().ToString().c_str());
        LogPrintf("block.hashMerkleRoot == %s\n", genesis.hashMerkleRoot.ToString().c_str());
        LogPrintf("block.nTime = %u \n", genesis.nTime);
        LogPrintf("block.nNonce = %u \n", genesis.nNonce);
        */

        assert(hashGenesisBlock == uint256("0x00003e27faf50e4ba9d3362ab81f6e16ecc843aa5718b6c04ecbcab8d4dac7f"));
        assert(genesis.hashMerkleRoot == uint256("0xece04c2f072a0d2d0fe96d658d59d4c39de0534433008d43bd06d8e3ed8119f6"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 40); // H
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125); // s
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 45); // K
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        vSeeds.emplace_back("hts-seed-1.dynu.net", "hts-seed-1.dynu.net");
        vSeeds.emplace_back("hts-seed-2.dynu.net", "hts-seed-2.dynu.net");

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 43200;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc2;
        pchMessageStart[1] = 0xa6;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0x71;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724");
        nDefaultPort = 48300;
        nRPCPort = 48310;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nTime    = 1537472018;
        genesis.nNonce = 527085;

        hashGenesisBlock = genesis.GetHash();

        /*if (true  && (genesis.GetHash() != hashGenesisBlock)) {
		// This will figure out a valid hash and Nonce if you're
		// creating a different genesis block:
			uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
			while (genesis.GetHash() > hashTarget)
			   {
				   ++genesis.nNonce;
				   if (genesis.nNonce == 0)
				   {
					   printf("NONCE WRAPPED, incrementing time");
					   ++genesis.nTime;
				   }
			   }


        hashGenesisBlock = genesis.GetHash();

        LogPrintf("TN block.GetHash() == %s\n", genesis.GetHash().ToString().c_str());
        LogPrintf("TN lock.hashMerkleRoot == %s\n", genesis.hashMerkleRoot.ToString().c_str());
        LogPrintf("TN block.nTime = %u \n", genesis.nTime);
        LogPrintf("TN block.nNonce = %u \n", genesis.nNonce);
         }*/

        assert(hashGenesisBlock == uint256("0x3e05376847abd22ec5ceb0fe007c5a5b6f03f68e83cfef487ee52150c1b2ed60"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63); // S
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125); // s
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 58); // Q
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xc2;
        pchMessageStart[1] = 0xa6;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0x71;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1520529257;
        genesis.nNonce = 527085;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";

        hashGenesisBlock = genesis.GetHash();

        /*if (true  && (genesis.GetHash() != hashGenesisBlock)) {
		// This will figure out a valid hash and Nonce if you're
		// creating a different genesis block:
			uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
			while (genesis.GetHash() > hashTarget)
			   {
				   ++genesis.nNonce;
				   if (genesis.nNonce == 0)
				   {
					   printf("NONCE WRAPPED, incrementing time");
					   ++genesis.nTime;
				   }
			   }
        }

        LogPrintf("RT block.GetHash() == %s\n", genesis.GetHash().ToString().c_str());
        LogPrintf("RT block.hashMerkleRoot == %s\n", genesis.hashMerkleRoot.ToString().c_str());
        LogPrintf("RT block.nTime = %u \n", genesis.nTime);
        LogPrintf("RT block.nNonce = %u \n", genesis.nNonce);
        */

        assert(hashGenesisBlock == uint256("0x6a71a0b38e1b390ed804809cea2d50a26bb9955a5fbc1c7ecbf03d06bdd01669"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
